#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "Response.hpp"
#include "Socket.hpp"
#include "Color.hpp"
#include "Request.hpp"
#include "CGI.hpp"

#include <vector>
#include <cstring>
#include <sys/socket.h>
#include <string>
#include <time.h>

class Client{
	int				client_socket;
	time_t			timing;
	unsigned long	addr;
	unsigned short	port;
	Client();

public:
	Response	response;
	Request		request;
	CGI			cgi;
	
	bool		is_cgi;
	std::string	host_request;
	bool		is_timed_out;
	std::string		peer_ip;

	Client(const int fd);
	Client(const Client &);
	Client& operator=(const Client &);
	~Client();

	int				get_sockfd() const;
	time_t			get_timing() const;
	unsigned long	get_addr() const;
	unsigned short	get_port() const;

	void	reset_timing();
	void	write_response();


};

class arr_Client : public std::vector<Client>
{
public:
	~arr_Client();
	void	close_connection(size_t i);
	void	show() const;
};

#endif