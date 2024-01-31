#include "Client.hpp"
#include <arpa/inet.h>

Client::Client(const int fd) : client_socket(fd)
{
	timing = time(NULL);

	struct sockaddr_in	address;
	socklen_t			len = sizeof(address);
	memset(&address, 0, len);

	if (getsockname(fd, (struct sockaddr *)&address, &len) == -1)
		throw(std::runtime_error("Calling to getsockname for client with fd: " + int_to_string(fd) ));

	addr = ntohl(address.sin_addr.s_addr);
	port = ntohs(address.sin_port);

	is_cgi = false;	
	host_request = "";
	is_timed_out = false;
	peer_ip = "";

}

Client::Client(const Client &ref)
{
	client_socket = ref.client_socket;
	timing = ref.timing;
	addr = ref.addr;
	port = ref.port;

	response = ref.response;
	request = ref.request;
	cgi = ref.cgi;

	is_cgi = ref.is_cgi;
	host_request = ref.host_request;
	is_timed_out = ref.is_timed_out;
	peer_ip = ref.peer_ip;

}

Client& Client::operator=(const Client &ref)
{
	client_socket = ref.client_socket;
	timing = ref.timing;
	addr = ref.addr;
	port = ref.port;

	response = ref.response;
	request = ref.request;
	cgi = ref.cgi;

	is_cgi = ref.is_cgi;
	host_request = ref.host_request;
	is_timed_out = ref.is_timed_out;
	peer_ip = ref.peer_ip;
	return *this;
}


Client::~Client()
{}

int	Client::get_sockfd() const
{
	return client_socket;
}

time_t	Client::get_timing() const
{ return timing; }

unsigned long	Client::get_addr() const
{ return addr; }
	
unsigned short	Client::get_port() const
{ return port; }

void	Client::reset_timing()
{
	timing = time(NULL);
}

void	Client::write_response()
{
	if (!response.is_fully_written())	
		response.write_to_fd(client_socket);
}

void	arr_Client::close_connection(size_t i)
{

	std::cout << timer();
	std::cout << RED << " Client closed with sockfd: " << this->operator[](i).get_sockfd();
	std::cout <<  " [" << this->operator[](i).peer_ip << "] " << get_string_ip_from_addr(this->operator[](i).get_addr());
	std::cout << ":" << this->operator[](i).get_port() << DEFAULT << ";\n";

	if ( close( this->operator[](i).get_sockfd() ) == -1 )
		std::cerr << "error closing client socket: " << strerror(errno) << '\n';

	this->operator[](i).response.close_fd_chunked();

	std::vector<Client>::iterator it = begin() + i;

	erase(it);
}

arr_Client::~arr_Client()
{
	while(size())
		close_connection(0);
}