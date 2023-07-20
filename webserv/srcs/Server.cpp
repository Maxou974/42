#include "Server.hpp"

Server::Server()
{
	server_ptrs[0] = &Server::set_server_name;
	server_ptrs[1] = &Server::set_root;
	server_ptrs[2] = &Server::set_host_port;
	server_ptrs[3] = &Server::set_location;
	server_ptrs[4] = &Server::set_methods;
	server_ptrs[5] = &Server::set_error_page;
	server_ptrs[6] = &Server::set_autoindex;
	server_ptrs[7] = &Server::set_client_body_size;
	server_ptrs[8] = &Server::set_redirection;
	server_ptrs[9] = &Server::set_uploaddir;
	server_ptrs[10] = &Server::set_index;

	server_name = "";
	root = ".";
	redirection = "";
	upload_dir = "";
	autoindex_is_on = false;
	
	index.push_back("index.html");

	method = 1;
	max_body_size = 0;

	addr_host_order = 0;
	port_host_order = 8081;
}

void	Server::init(int dir_index, const std::string& value, size_t l)
{
	line = l;
	(this->*server_ptrs[dir_index])(value);
}

void 	Server::set_server_name(const std::string& value)
{ server_name = value; }

void 	Server::set_location(const std::string& value)
{
	Location	tmp;
	std::pair<std::string, size_t> t;
	t = tmp.set(value, line);
	if (t.first != "no_error")
		throw(Server::ServerSyntaxError("location: can't recognize: " + t.first, count_line(value, t.second) + line - 1));
	location.push_back(tmp);
}

void 	Server::set_host_port(const std::string& value)
{
	host_port = value;
	size_t pos;
	if ( (pos = value.find(":")) != std::string::npos )
	{
		std::string left(value, 0, pos);
		std::string right(value, pos + 1, value.size() - pos);
		
		if (check_host(left) || (get_host_value(left)) == -1)
			throw(ServerSyntaxError("listen: invalid host: X.X.X.X", line));

		addr_host_order = static_cast<unsigned long>(get_host_value(left));

		if (get_port_value(right) == -1)
			throw(ServerSyntaxError("listen: invalid port", line));

		port_host_order = static_cast<unsigned short>(get_port_value(right));
	}
	else
	{
		if (value.find('.') != std::string::npos)
		{
			if (check_host(value) || (get_host_value(value)) == -1)
				throw(ServerSyntaxError("listen: invalid host: X.X.X.X", line));

			addr_host_order = static_cast<unsigned long>(get_host_value(value));
		}
		else 
		{
			if (get_port_value(value) == -1)
				throw(ServerSyntaxError("listen: invalid port", line));

			port_host_order = static_cast<unsigned short>(get_port_value(value));
		}
	}
}

void 	Server::set_root(const std::string& value)
{
	std::vector<std::string> vec = parse_value(value);
	
	if (vec.size() != 1)
		throw(SSERROR("root: invalid number of arg", line));
	root = vec[0];
}

void 	Server::set_methods(const std::string& value)
{
	std::vector<std::string> vec = parse_value(value);

	if (vec.size() > 3 || vec.size() == 0)
		throw(SSERROR("allow_method: invalid number of arg", line));
	
	if (1 < std::count(vec.begin(), vec.end(), "GET") ||
		1 < std::count(vec.begin(), vec.end(), "POST") ||
		1 < std::count(vec.begin(), vec.end(), "DELETE"))
		throw(SSERROR("allow_method: duplicate value", line));
	
	method = 0;
	for (size_t i = 0; i < vec.size(); i++)
	{
		if (vec[i] == "GET")
			method += 1;
		else if (vec[i] == "POST")
			method += 2;
		else if (vec[i] == "DELETE")
			method += 4;		
		else
			throw(SSERROR("allow_method: invalid value: " + vec[i], line));
	}
}

void	Server::set_error_page(const std::string& value)
{
	std::vector<std::string> vec = parse_value(value);

	if (vec.size() < 2 || vec[vec.size() - 1] == "")
		throw(ServerSyntaxError("error_page: invalid number of arg", line));

	size_t i = 0;
	int32_t t;
	for (i = 0; i < vec.size() - 1; i++)
	{
		t = get_port_value(vec[i]);
		if (t < 0 || t > 599)
			throw(ServerSyntaxError("error_page: invalid value: " + vec[i], line));
	}
	
	for (i = 0; i < vec.size() - 1; i++)
		error_page.add_error_pages(get_port_value(vec[i]), vec[vec.size() - 1]);
}

void	Server::set_autoindex(const std::string& value)
{
	std::vector<std::string> vec = parse_value(value);

	if (vec.size() != 1)
		throw(ServerSyntaxError("autoindex: invalid number of arg", line));
	if (vec[0] == "on")
		autoindex_is_on = true;
	else if (vec[0] == "off")
		autoindex_is_on = false;
	else
		throw(ServerSyntaxError("autoindex: invalid value (on | off)", line));
}

void	Server::set_index(const std::string& value)
{
	index = parse_value(value);
	
	if (index.size() == 0)
		throw(SSERROR("index: invalid number of arg", line));
}

void	Server::set_redirection(const std::string &value)
{
	std::vector<std::string> vec = parse_value(value);

	if (vec.size() != 1)
		throw(SSERROR("return: invalid number of arg", line));
	redirection = vec[0];
}

void Server::set_client_body_size(const std::string &value)
{
	std::vector<std::string> vec = parse_value(value);

	if (vec.size() != 1)
		throw(ServerSyntaxError("client_max_body_size: invalid number of arg", line));

	for (size_t i = 0; i < vec[0].size(); i++)
		if (!isdigit(vec[0][i]))
			throw(ServerSyntaxError("client_max_body_size: invalid value", line));

	max_body_size = string_to_size_t(vec[0]);

	if (vec[0] != int_to_string(max_body_size))
		throw(ServerSyntaxError("client_max_body_size: value overflow", line));

}

void	Server::set_uploaddir(const std::string& value)
{
	std::vector<std::string> vec = parse_value(value);
	if (vec.size() != 1)
		throw(SSERROR("upload_dir: invalid number of arg", line));
	upload_dir = vec[0];
}

const std::string&	Server::get_server_name() const
{ return server_name; }

const std::string&	Server::get_root() const
{ return root; }

const std::string&	Server::get_upload_dir() const
{ return upload_dir; }

const std::string&	Server::get_redirection() const
{ return redirection; }

const ErrorPages&	Server::get_error_pages() const
{ return error_page; }

const bool&			Server::is_autoindex_on() const
{ return autoindex_is_on; }

size_t	Server::get_max_body_size() const
{ return max_body_size; }

const std::vector<Location>&	Server::get_location() const
{ return location; }

const std::vector<std::string>& Server::get_index() const
{ return index; }

unsigned long	Server::get_addr_host_order() const
{ return addr_host_order; }

unsigned short	Server::get_port_host_order() const
{ return port_host_order; }


bool	Server::get_is_allowed() const
{
	return 0b1 & method;
}

bool	Server::post_is_allowed() const
{
	return 0b10 & method;
}

bool	Server::delete_is_allowed() const
{
	return 0b100 & method;
}

void	Server::show()
{ 
	std::cout << "\nSERVER\n";
	std::cout << " server_name:" << server_name << '\n';
	std::cout << " root:" << root << '\n';
	std::cout << " host_port:" << host_port << '\n';
	std::cout << " port:" << port_host_order << '\n';
	std::cout << " host:" << addr_host_order << '\n';
	std::cout << " return:" << redirection << '\n';
	std::cout << " autoindex_is_on:" << autoindex_is_on << '\n';
	std::cout << " method:" << method << '\n';
	std::cout << " upload_dir:" << upload_dir << '\n';
	std::cout << " index: \n";
	for (size_t i = 0; i < index.size(); i++)
		std::cout << '\t' + index[i] << '\n';
	std::cout << " max_body_size: " << max_body_size << '\n';
	for (size_t i = 0; i < location.size(); i++)
		location[i].show();
	std::cout << "ERROR PAGES\n";
	error_page.show();
	std::cout << "END ERROR PAGES\n";
	std::cout << "ENDSERVER\n";
}


Server::ServerSyntaxError::ServerSyntaxError(const std::string &where, int line)
{
	here = "Syntax error in: " + where + " : at line " + int_to_string(line); 
}


char const * Server::ServerSyntaxError::what() const throw()
{ return here.c_str(); }

Server::ServerSyntaxError::~ServerSyntaxError() throw(){}