#ifndef SERVER_HPP
#define SERVER_HPP

#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <cctype>
#include <cstdlib>
#include <exception>
#include <cstdio>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <algorithm>
#include <errno.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>

#include "Parsing.hpp"
#include "ErrorPages.hpp"
#include "Location.hpp"
#include "webserv_utility.h"

class Location;

#define SERVER_DIRECTIVE_NBR 11

class Server
{
	typedef	void( Server::*fct_ptr )( const std::string & );
	fct_ptr	server_ptrs[SERVER_DIRECTIVE_NBR];

	std::string 			server_name;
	std::string 			root;
	std::string 			host_port;
	std::string				redirection;
	std::vector<std::string>index;
	std::vector<Location> 	location;
	ErrorPages				error_page;
	bool					autoindex_is_on;
	int						method;
	size_t					max_body_size;
	std::string				upload_dir;

	unsigned long	addr_host_order;
	unsigned short	port_host_order;

	size_t	line;

	public:
	Server();
	void	init(int dir_index, const std::string &value, size_t l);
	void	set_server_name(const std::string &value);
	void	set_location(const std::string &value);
	void	set_host_port(const std::string &value);
	void	set_root(const std::string &value);
	void	set_methods(const std::string &value);
	void	set_error_page(const std::string &value);
	void	set_autoindex(const std::string &value);
	void	set_index(const std::string &value);
	void	set_redirection(const std::string &value);
	void	set_client_body_size(const std::string &value);
	void	set_uploaddir(const std::string& value);


	const std::string&	get_server_name() const;
	const std::string&	get_root() const;
	const std::string&	get_upload_dir() const;
	const std::string&	get_redirection() const;
	const ErrorPages&	get_error_pages() const;
	const bool&			is_autoindex_on() const;

	size_t	get_max_body_size()const;

	const std::vector<Location>&	get_location() const;
	const std::vector<std::string>& get_index() const;

	unsigned long		get_addr_host_order()	const;
	unsigned short		get_port_host_order()	const;


	bool				get_is_allowed()const;
	bool				post_is_allowed()const;
	bool				delete_is_allowed()const;

	void	show();

	class ServerSyntaxError : public std::exception{
		std::string here;
		char const * what()const throw();
		public:
		ServerSyntaxError(const std::string &where, int line);
		virtual ~ServerSyntaxError() throw();
	};
};

class arr_Server : public std::vector<Server>
{

};

#endif
