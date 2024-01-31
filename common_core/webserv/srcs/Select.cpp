#include "Select.hpp"

static void	add_serv_socket_to_read_set(arr_Socket &arr_socket, FdSet &read_set)
{
	for (size_t i = 0; i < arr_socket.size(); i++)
		read_set.add_fd(arr_socket[i].get_sockfd());
}


void	handle_read_set(arr_Server &server_v, arr_Client &client_arr, \
			arr_Socket &server_socket, FdSet &read_set, FdSet &write_set)
{
	int fd; (void)server_v;
	// std::cout << GREEN << "HANDLE READ SET" << DEFAULT <<'\n';
	for (size_t i = 0; i < server_socket.size(); i++)
	{
		if ( read_set.is_set( fd = server_socket[i].get_sockfd() ) )
		{
			struct sockaddr_in	address;
			socklen_t			len = sizeof(address);
			memset(&address, 0, len);

			int tmp = accept(fd, (struct sockaddr*)&address, &len);
			
			if (tmp == -1)
				std::cerr << RED << "accept system call: " << strerror(errno) << DEFAULT << '\n';
			else
			{
				if (fcntl(tmp, F_SETFL, O_NONBLOCK | O_CLOEXEC) < 0)
				{
					std::cerr << "fcntl accepting socket: " << tmp << " : " << strerror(errno) << '\n';
					close(tmp);
					continue;
				}

				try
				{
					client_arr.push_back(Client(tmp));
				}
				catch ( std::runtime_error &e)
				{
					std::cerr << RED << e.what() << '\n';
					close(tmp);
					continue;
				}

				client_arr[client_arr.size() - 1].peer_ip = get_string_ip_from_addr(ntohl(address.sin_addr.s_addr)) + ":" + int_to_string(ntohs(address.sin_port));
				read_set.add_fd(tmp);

				std::cout << timer();
				std::cout << GREEN << " New client accepted with sockfd: " << tmp;
				std::cout <<  " [" << client_arr[client_arr.size() - 1].peer_ip << "] " << get_string_ip_from_addr(client_arr[client_arr.size() - 1].get_addr());
				std::cout << ":" << client_arr[client_arr.size() - 1].get_port() << DEFAULT << ";\n";

			}
		}
	}
	for (size_t i = 0; i < client_arr.size(); i++)
	{
		if ( read_set.is_set( fd = client_arr[i].get_sockfd() ) )
		{
			Client& cli = client_arr[i];
			ssize_t read_ret;
			char buffer[4097];
			read_ret = read(fd, buffer, 4096);
			buffer[read_ret] = 0;
			if (read_ret < 0)
				std::cerr << "ERROR READING: " << strerror(errno) << '\n';
			else if (read_ret == 0)
				void();
			else
			{

				cli.request.concatenate_request(buffer, read_ret);
				
				int ret = 200;
				if (cli.request.header_is_complete == false)
				{	
					ret = cli.request.parse_request();
					cli.host_request = cli.request.get_header_value_from_key("Host");
				}
				
				if (ret == 200)
				{
					const Server& serv = resolve_server(server_v, cli);
					ret = cli.request.parse_request_body(serv.get_max_body_size());
				}

				if (ret != 200)
				{
					cli.request.request_is_complete = true;
					cli.is_cgi = false;
					cli.response.build_error(resolve_server(server_v, cli).get_error_pages(), ret);
				}	
			}

			if ( read_ret == -1 || read_ret == 0 )
			{
				client_arr.close_connection(i);
				read_set.remove_fd(fd);	
				write_set.remove_fd(fd);
			}
			else if (cli.request.request_is_complete)
			{
				std::cout << timer();
				std::cout << " [" << cli.request.get_method() << " : " << cli.request.get_uri()<< "]\n";
				write_set.add_fd(fd);
				read_set.remove_fd(fd);
			}
		}
	}
}

bool	uri_is_cgi(const Server& serv, const std::string &uri)
{
	int	loc_index = get_location_index(serv, uri);

	if (loc_index == -1)
		return false;
	if (serv.get_location()[loc_index].get_cgi_extension() != ".php")
		return false;
	if (uri.find(".php") == std::string::npos)
		return false;
	return true;
}

void	build_response(const arr_Server& serv_arr, Client& client)
{
	const Server&	serv = resolve_server(serv_arr, client);
	Response&	client_response = client.response;
	const std::string request_method = client.request.get_method();

	if (request_method == "GET")
	{
		if (uri_is_cgi(serv, client.request.get_uri()))
		{

			if (serv.get_location()[get_location_index(serv, client.request.get_uri())].get_is_allowed() == false)
			{
				client.response.build_error(serv.get_error_pages(), 405);
				return;
			}
			if (client.cgi.is_init == false)
			{
				client.is_cgi = true;
				client.cgi.init(serv, client.request, GET);
			}
			else
			{
				int ret = client.cgi.process(client.response.body);

				if (ret != 200 && ret != 0)
				{
					client_response.build_error(serv.get_error_pages(), ret);
					client.is_cgi = false;
				}
				if (ret == 200)
				{
					client_response.set_status_line(200);

					size_t end_ = find_string_in_vector(client_response.body, "\r\n\r\n");
					if(end_ == std::string::npos) 
					{
						client_response.add_header("Content-Type", "text/html");
					}
					else
					{
						ssize_t end_ind = end_;
						while(end_ind > 0)
						{
							size_t end_index = find_string_in_vector(client_response.body, "\r\n");
							std::string line(client_response.body.begin(), client_response.body.begin() + end_index + 2);
							if (line.find("Status") != std::string::npos)
								client.response.set_status_line(std::string(line, 8));
							else
								client_response.add_header(line);
							client_response.body.erase(client_response.body.begin(), client_response.body.begin() + end_index + 2);
							end_ind -= end_index + 2;
							if (client_response.body[0] == '\r' && client_response.body[1] == '\n')
							{
								client_response.body.erase(client_response.body.begin(), client_response.body.begin() + 2);
								end_ind -= end_index + 2;
							}
						}
					}
					client_response.add_header("Content-Length", int_to_string(client_response.body.size()));
					client_response.build();
					client.is_cgi = false;
				}
			}
		}
		else if (client.request.get_query_string() != "")
			client.response.build_error(serv.get_error_pages(), 400);
		else if (client_response.is_fully_written() && !client_response.is_chunked_())
			client_response.build_get(serv, client.request.get_uri());
		else if(client_response.is_fully_written() && client_response.is_chunked_())
			client_response.get_next_chunk(serv.get_error_pages());
	}
	else if (request_method == "POST")
	{
		if (uri_is_cgi(serv, client.request.get_uri()))
		{
			if (serv.get_location()[get_location_index(serv, client.request.get_uri())].post_is_allowed() == false)
			{
				client.response.build_error(serv.get_error_pages(), 405);
				return;
			}
			if (client.cgi.is_init == false)
			{
				client.is_cgi = true;
				client.cgi.init(serv, client.request, POST);
			}
			else
			{
				int ret = client.cgi.process(client.response.body);

				if (ret == 200)
				{
					client_response.set_status_line(200);

					size_t end_ = find_string_in_vector(client_response.body, "\r\n\r\n");
					if(end_ == std::string::npos) 
					{
						client_response.add_header("Content-Type", "text/html");
					}
					else
					{
						ssize_t end_ind = end_;
						while(end_ind > 0)
						{
							size_t end_index = find_string_in_vector(client_response.body, "\r\n");
							std::string line(client_response.body.begin(), client_response.body.begin() + end_index + 2);
							if (line.find("Status") != std::string::npos)
								client.response.set_status_line(std::string(line, 8));
							else
								client_response.add_header(line);
							client_response.body.erase(client_response.body.begin(), client_response.body.begin() + end_index + 2);
							end_ind -= end_index + 2;
							if (client_response.body[0] == '\r' && client_response.body[1] == '\n')
							{
								client_response.body.erase(client_response.body.begin(), client_response.body.begin() + 2);
								end_ind -= end_index + 2;
							}
						}
					}
					client_response.add_header("Content-Length", int_to_string(client_response.body.size()));
					client_response.build();
					client.is_cgi = false;
				}
				else if (ret != 0)
				{
					client_response.build_error(serv.get_error_pages(), ret);
					client.is_cgi = false;
				}
			}
		}
		else if (client.request.get_header_value_from_key("Content-Type") != "")
		{
			std::string content_type_value = client.request.get_header_value_from_key("Content-Type");

			if (content_type_value.find("multipart/form-data;") == std::string::npos)
			{
				client_response.build_error(serv.get_error_pages(), 501);
			}
			else
			{
				client_response.build_post(serv, client.request);
			}
		}
		else
		{
			client_response.build_error(serv.get_error_pages(), 501);
		}
	}
	else if (request_method == "DELETE")
	{
		client_response.build_delete(serv, client.request);
	}
	else
		client.response.build_error(serv.get_error_pages(), 501);

}



void	handle_write_set(arr_Server &server_v, arr_Client &client_arr,\
						 FdSet &read_set, FdSet &write_set)
{
	// std::cout << RED << "HANDLE WRITE SET" << DEFAULT << '\n';
	(void)server_v;
	int client_fd;

	for (size_t i = 0; i < client_arr.size(); i++)
	{
		client_fd = client_arr[i].get_sockfd();

		if ( write_set.is_set(client_fd) )
		{

			if (client_arr[i].is_timed_out)
			{
				Response timeout;
				const Server&	serv = resolve_server(server_v, client_arr[i]);
	
				timeout.build_error(serv.get_error_pages(), 408);

				write(client_fd, timeout.get_Response(), timeout.size());
				write_set.remove_fd(client_fd);
				read_set.remove_fd(client_fd);
				client_arr.close_connection(i);
			}
			else
			{
				Response&	client_response = client_arr[i].response;
				client_arr[i].host_request = client_arr[i].request.get_host();

				if (client_arr[i].response.is_fully_written() == true)
				{
					build_response(server_v, client_arr[i]);
				}

				try{
					if (client_arr[i].is_cgi == false)
						client_arr[i].write_response();
				}
				catch(std::runtime_error &e)
				{
					std::cout << "client with fd: " << client_fd << " error: " << e.what() << '\n'; 
					client_arr.close_connection(i);
					read_set.remove_fd(client_fd);
					write_set.remove_fd(client_fd);
					continue;
				}
				
				client_arr[i].reset_timing();

				if (	client_arr[i].is_cgi == false
						&& client_response.is_fully_written()
						&& !client_response.is_chunked_())
				{
					client_arr.close_connection(i);
					read_set.remove_fd(client_fd);
					write_set.remove_fd(client_fd);
					continue;
				}
				else
				{
					continue;
				}

			}
		}
	}
}

bool running = true;

void	sig_handler(int signum)
{
	if (signum == SIGINT)
		running = false;
	
}

void	handle_timeout_client(arr_Client &client, FdSet &read_set, FdSet &write_set)
{
	for (size_t i = 0; i < client.size(); i++)
	{
		double diff = difftime(time(NULL), client[i].get_timing());
		if (TIMEOUT_CLIENT < diff)
		{
			read_set.remove_fd(client[i].get_sockfd());
			client[i].is_timed_out = true;
			write_set.add_fd(client[i].get_sockfd());
		}
	}
}

void	call_select(arr_Server &server_v, arr_Socket &server_socket)
{
	FdSet		read_set, write_set;
	arr_Client	client;
	int			select_ret;
	struct timeval ti;
	

	signal(SIGINT, &sig_handler);
	signal(SIGPIPE, SIG_IGN);
	
	(void)server_v;

	add_serv_socket_to_read_set(server_socket, read_set);

	while(running)
	{
		read_set.build_set();
		write_set.build_set();

		ti.tv_sec = 5;
		ti.tv_usec = 0;
		select_ret = select(_MAX_FD_ + 1, &(read_set.get_set()), &(write_set.get_set()), 0, &ti);


		if (select_ret == -1 && running)
		{
			running = false;
			std::cerr << "select returned -1: " << strerror(errno) << '\n';
		}
		else if (select_ret == 0)
		{
			handle_timeout_client(client, read_set, write_set);
		}
		else if (select_ret > 0 && running)
		{
			handle_timeout_client(client, read_set, write_set);
			handle_read_set(server_v, client, server_socket, read_set, write_set);
			handle_write_set(server_v, client, read_set, write_set);
		}
		// sleep(1);
	}
}