#include "Response.hpp"
#include "Multipart.hpp"

Response::Response() : bytes_wrote(0),  is_chunked(0), fd_chunked(-1), is_first_chunk_call(true)
{}

Response::Response(const Response &ref)
{
	response = ref.response;
	body = ref.body;
	header = ref.header;
	status = ref.status;
	bytes_wrote = ref.bytes_wrote;
	is_chunked = ref.is_chunked;
	fd_chunked = ref.fd_chunked;
	is_first_chunk_call = ref.is_first_chunk_call;
}

Response& Response::operator=(const Response &ref)
{
	response = ref.response;
	body = ref.body;
	header = ref.header;
	status = ref.status;
	bytes_wrote = ref.bytes_wrote;
	is_chunked = ref.is_chunked;
	fd_chunked = ref.fd_chunked;
	is_first_chunk_call = ref.is_first_chunk_call;
	return *this;
}

Response::~Response()
{ }


const unsigned char * Response::get_Response() const
{
	return response.data();
}

size_t	Response::size() const
{
	return response.size();
}

void	Response::add_header(const std::string &field, const std::string& value)
{
	header.push_back(field + ": " + value + "\r\n");
}

void	Response::add_header(const std::string& full_header)
{
	header.push_back(full_header);
}

void	Response::set_status_line(const int code)
{
	MAP_StatCode::const_iterator it = map_status_code.find(code);
	if (it == map_status_code.end())
	{
		std::cout << "MISSING CODE " << code << "IN MAP_STATUS_CODE\n";
		return;
	}
	status = "HTTP/1.1 " + it->second + "\r\n";
}

void	Response::set_status_line(const std::string& str)
{
	status = "HTTP/1.1 " + str;
}

int	Response::set_body_from_file(const std::string& path)
{
	errno = 0;
	access(path.c_str(), F_OK);

	if (errno == ENOENT)
		return 404;
	else if (errno)
		return 500;
	
	std::fstream file( path.c_str(), std::ios_base::binary | std::fstream::in);
	body.clear();
	if (file.is_open())
	{
		char c;
		while (!file.eof())
		{
			file.get(c);
			if (file.bad() || (file.fail() && !file.eof()))
				return 500; 
			if (!file.fail())
				body.push_back(c);
		}
	}
	else
		return 403;
	add_header("Content-Length", int_to_string(body.size()));
	add_header("Content-Type", get_type_from_file(path));
	return 200;
}

void	Response::build_autoindex(const std::string &full_path, const std::string &uri, const Server& serv)
{
	int ret = autoindex(body, full_path, uri);
		
	if (ret == 200)
	{
		set_status_line(ret);
		add_header("Content-Length", int_to_string(body.size()));
		add_header("Content-Type", "text/html");
		build();
	}
	else
	{
		build_error(serv.get_error_pages(), ret);						
	}

}

void	Response::build_error(const ErrorPages& error_info, const int code)
{
	clear();
	MAP_StatCode::const_iterator it = map_status_code.find(code);
	if (it == map_status_code.end())
	{
		std::cerr << "NO MAP STATUS CODE FOR: " << code << '\n';
		return;
	}

	set_status_line(it->first);

	int ret = set_body_from_file(error_info.get_path(code));

	if (ret != 200)
	{
		body.clear();
		write_string_to_vector( get_default_error_pages(code), body );
		add_header("Content-Length", int_to_string(body.size()));
		add_header("Content-Type", "text/html");
	}
	build();
}

void	Response::build_redirect(const int code, const std::string &location)
{
	set_status_line(code);
	add_header("Location", location);
	build();
}

int		get_location_index(const Server &serv, const std::string& uri)
{
	const std::vector<Location>& loc = serv.get_location();
	
	for (size_t i = 0; i < loc.size(); i++)
	{
		if (uri.find( loc[i].get_path() ) == 0)
			return i;
	}
	return -1;
}


bool	path_exist(const std::string& path)
{
	if (access(path.c_str(), F_OK) == 0)
		return true;
	return false;
}

size_t	search_for_index(const std::vector<std::string>& index_tab, const std::string& path)
{
	for (size_t i = 0; i < index_tab.size(); i++)
	{
		const std::string doc_path = path + index_tab[i];
		if (path_exist(doc_path))
			return i;
	}
	return index_tab.size();
}

int	is_a_directory(const std::string& path)
{
	struct stat st;
	
	int ret = stat(path.c_str(), &st);

	if (ret == -1)
		return 500;
	return S_ISDIR(st.st_mode);
}

ssize_t	get_file_size(const std::string& path)
{
	struct stat st;

	int ret = stat(path.c_str(), &st);

	if (ret == -1)
		return -1;
	
	return st.st_size;
}

void	Response::set_body_if_file_set_redir_if_dir(const std::string& path, const std::string&uri ,const Server& serv)
{
	int is_dir = is_a_directory(path);
	
	if (is_dir == 500)
	{
		build_error(serv.get_error_pages(), 500);
	}
	else if (is_dir)
	{
		build_redirect(301, uri + "/");
	}
	else
	{
		int ret;
		ssize_t size_file = get_file_size(path);

		if (size_file == -1)
		{
			build_error(serv.get_error_pages(), 500);
			return;
		}
		else if (size_file > MIN_FILE_SIZE_FOR_CHUNKED)
		{
			errno = 0;
			int err = access(path.c_str(), R_OK);

			if (errno == EACCES)
				ret = 403;
			else if (err == -1)
				ret = 500;
			else
			{
				fd_chunked = open(path.c_str(), O_RDONLY | O_CLOEXEC);
				add_header("Content-Type", get_type_from_file(path));
				add_header("Transfer-Encoding", "chunked");
				set_status_line(200);
				is_chunked = true;
				return;
			}
		}
		else
			ret = set_body_from_file(path);

		if (ret == 200)
		{
			set_status_line(ret);
			build();
		}
		else
		{
			build_error(serv.get_error_pages(), ret);						
		}				
	}	
}

void	Response::build_get(const Server &serv, const std::string& uri)
{
	clear();
	std::string redir;
	std::string full_path;
	std::vector<std::string> index_tab;
	bool	is_autoindex_on;
	bool	get_allowed;
	
	int	loc_index = get_location_index(serv, uri);

	if (loc_index == -1)
	{
		redir = serv.get_redirection();
		full_path = serv.get_root() + uri;
		index_tab = serv.get_index();
		is_autoindex_on = serv.is_autoindex_on();
		get_allowed = serv.get_is_allowed();
	}
	else
	{
		const Location& loc = serv.get_location()[loc_index];
		std::string trim_uri = uri;

		redir = loc.get_redirection();
		full_path = loc.get_alias() + trim_uri.erase(0, loc.get_path().size());
		index_tab = loc.get_index();
		is_autoindex_on = loc.is_autoindex_on();	
		get_allowed = loc.get_is_allowed();	
	}

	if (redir != "")
	{
		build_redirect(302, redir);
		return;
	}
	if (get_allowed == false)
	{
		build_error(serv.get_error_pages(), 405);
		return;
	}

	if ( *(full_path.end() - 1) == '/')
	{
		size_t index = search_for_index(index_tab, full_path);
		if ( index < index_tab.size() )
		{
			set_body_if_file_set_redir_if_dir(full_path + index_tab[index], uri, serv);
		}
		else if (is_autoindex_on)
		{
			build_autoindex(full_path, uri, serv);
		}
		else
		{
			if (path_exist(full_path))
				build_error(serv.get_error_pages(), 403);
			else
				build_error(serv.get_error_pages(), 404);
		}
	}
	else
	{
		if (path_exist(full_path))
		{
			set_body_if_file_set_redir_if_dir(full_path, uri, serv);
		}
		else
		{
			build_error(serv.get_error_pages(), 404);
		}
	}
}

void	Response::build_post(const Server &serv, Request& request)
{
	clear();
	std::string 	full_path;
	bool			post_allowed;
	std::string		upload_dir;
	
	int	loc_index = get_location_index(serv, request.get_uri());

	if (loc_index == -1)
	{
		full_path = serv.get_root() + request.get_uri();
		post_allowed = serv.post_is_allowed();
		upload_dir = serv.get_upload_dir();
	}
	else
	{
		const Location& loc = serv.get_location()[loc_index];
		std::string trim_uri = request.get_uri();

		full_path = loc.get_alias() + trim_uri.erase(0, loc.get_path().size());
		post_allowed = loc.post_is_allowed();
		upload_dir = loc.get_upload_dir();
	}

	if (post_allowed == false)
	{
		build_error(serv.get_error_pages(), 405);
		return;
	}
	if(upload_dir == "")
	{
		build_error(serv.get_error_pages(), 403);
		return;
	}

	int is_dir = is_a_directory(upload_dir);

	if (is_dir == false || is_dir == 500)
	{
		build_error(serv.get_error_pages(), 500);
		return;		
	}

	Multipart multi(request.get_header_value_from_key("Content-Type"), request.get_body());

	multi.set_index_vector();

	multi.set_info_vector();

	if (multi.info_vector.size() == 0)
	{
		build_error(serv.get_error_pages(), 400);
		return;
	}

	for(size_t i = 0; i < multi.info_vector.size(); i++)
	{
		std::string	file_name = upload_dir + multi.info_vector[i].file_name;

		std::ofstream fs(file_name.c_str(), std::ios_base::binary | std::ios_base::out );

		if (fs.is_open() == false)
		{
			build_error(serv.get_error_pages(), 500);
			return;
		}
		size_t start = multi.info_vector[i].start_data;
		size_t end = multi.info_vector[i].end_data - 2;

		for (size_t i = start; i < end; i++)
		{
			if ( fs.fail() || fs.bad() )
			{
				fs.close();
				build_error(serv.get_error_pages(), 500);
				return;
			}
			fs << request.get_body()[i];
		}
		fs.close();
	}

	build_error(serv.get_error_pages(), 201);

}

void	Response::build_delete(const Server &serv, Request& request)
{
	clear();
	std::string 	full_path;
	bool			delete_allowed;
	
	int	loc_index = get_location_index(serv, request.get_uri());

	if (loc_index == -1)
	{
		full_path = serv.get_root() + request.get_uri();
		delete_allowed = serv.delete_is_allowed();
	}
	else
	{
		const Location& loc = serv.get_location()[loc_index];
		std::string trim_uri = request.get_uri();

		full_path = loc.get_alias() + trim_uri.erase(0, loc.get_path().size());
		delete_allowed = loc.delete_is_allowed();
	}
	if (delete_allowed == false)
	{
		build_error(serv.get_error_pages(), 405);
	}
	else
	{
		errno = 0;
		
		int ret = std::remove(full_path.c_str());

		if (ret == 0)
			build_error(serv.get_error_pages(), 200);
		else if (errno == ENOENT)
			build_error(serv.get_error_pages(), 404);
		else if (errno == EACCES)
			build_error(serv.get_error_pages(), 403);
		else
			build_error(serv.get_error_pages(), 500);
	}
}

void	Response::write_to_fd(const int fd)
{
	ssize_t	tmp;

	tmp = write(fd, response.data() + bytes_wrote, response.size() - bytes_wrote);

	if (tmp < 0)
	{
		close_fd(fd_chunked);
		throw(std::runtime_error(strerror(errno)));
	}

	bytes_wrote += tmp;
}

void	write_char_to_vector(const char *buffer, std::vector<unsigned char>&body, ssize_t size)
{
	for (ssize_t i = 0; i < size; i++)
		body.push_back(buffer[i]);
}

void	Response::get_next_chunk(const ErrorPages& error_p)
{
	if (fd_chunked == -1)
	{
		build_error(error_p, 500);
		is_chunked = false;
	}
	else
	{
		if (is_first_chunk_call)
		{	
			int fc = fcntl(fd_chunked, F_SETFL, O_NONBLOCK);
			if (fc == -1)
			{
				std::cerr << "fd: " << fd_chunked << "  ";
				std::cerr << "fcntl error in first chunk call: " << strerror(errno) <<'\n';
				build_error(error_p, 500);
				close_fd(fd_chunked);
				is_chunked = false;
				return;
			}
		}

		char buffer[CHUNKED_REQUEST_BUFFER_SIZE];
		fd_set set;
		FD_ZERO(&set);
		FD_SET(fd_chunked, &set);

		int select_ret = select(fd_chunked + 1, &set, 0, 0, 0);

		if (select_ret != 1)
		{
			if (is_first_chunk_call)
			{
				std::cerr << "fd: " << fd_chunked << '\n';
				std::cerr << "select error in first chunk call: " << strerror(errno) <<'\n';
				build_error(error_p, 500);
				close_fd(fd_chunked);
				is_chunked = false;
				return;
			}
			else
			{
				close_fd(fd_chunked);
				clear();
				return;		
			}
		}

		ssize_t ret = read(fd_chunked, buffer, CHUNKED_REQUEST_BUFFER_SIZE);

		if (is_first_chunk_call && ret == -1)
		{
			std::cerr << "fd: " << fd_chunked << '\n';
			std::cerr << "read return -1 in first chunk call\n" << strerror(errno) <<'\n';
			close_fd(fd_chunked);
			build_error(error_p, 500);
			is_chunked = false;
			return;
		}
		else if (ret == -1)
		{
			close_fd(fd_chunked);
			clear(); //doing nothing because already send headers so just close connection
		}
		else if (ret == 0)
		{
			close_fd(fd_chunked);
			clear();
			write_string_to_vector("0\r\n\r\n", response);
		}
		else if(is_first_chunk_call)
		{
			write_char_to_vector(buffer, body, ret);
			chunk_the_vector(body, ret);
			is_first_chunk_call = false;
			build();
		}
		else
		{
			response.clear();
			body.clear();
			bytes_wrote = 0;
			write_char_to_vector(buffer, response, ret);
			chunk_the_vector(response, ret);
		}
	}
}

bool	Response::is_fully_written() const
{
	return static_cast<size_t>(bytes_wrote) == response.size();
}

bool	Response::is_chunked_() const
{ return is_chunked; }

void	Response::close_fd(int &fd)
{
	if (fd != -1)
	{
		close(fd);
		fd = -1;
	}
}

void	Response::close_fd_chunked()
{
	close_fd(fd_chunked);
}

void	Response::build()
{
	response.clear();

	add_header("Server", "shammouc, mabriel 42 webserver");
	add_header("Connection", "close");
	add_header("Date", get_gmt_time(RESPONSE_FORM, time(NULL)));

	for (size_t i = 0; i < status.size(); i++)
		response.push_back(status[i]);

	for (size_t i = 0; i < header.size(); i++)
		for(size_t j = 0; j < header[i].size(); j++)
			response.push_back(header[i][j]);

	response.push_back('\r');
	response.push_back('\n');

	for (size_t i = 0; i < body.size(); i++)
		response.push_back(body[i]);

}

void	Response::clear()
{
	status = "";
	header.clear();
	body.clear();
	response.clear();
	bytes_wrote = 0;

	close_fd(fd_chunked);
	is_chunked = false;
	is_first_chunk_call = true;
}


