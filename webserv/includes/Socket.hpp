#ifndef SOCKET_HPP
#define SOCKET_HPP

#include "Server.hpp"
#include "Color.hpp"
#include <exception>
#include <unistd.h>

class Socket{

	unsigned long	addr;
	unsigned short	port;
	int					sockfd;
	struct sockaddr_in	address;

public:
	Socket(unsigned long a, unsigned short p);
	Socket(const Socket &);
	Socket& operator=(const Socket &);
	~Socket();


	void	set_socket();
	int		get_sockfd()const;

	class	SocketException : public std::exception{
		std::string str;
		char const * what() const throw();
		public:
		SocketException(std::string hehe);
		virtual ~SocketException() throw();
	};
};



class arr_Socket : public std::vector<Socket> 
{

public:
	void 	show() const;
	bool	is_in_the_array(int);

};

void	socketing(arr_Server&, arr_Socket &);


#endif