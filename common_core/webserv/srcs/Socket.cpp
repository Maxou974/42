#include "Socket.hpp"

Socket::Socket(unsigned long a, unsigned short p) : addr(a), port(p)
{
	sockfd = -1;
}

Socket::Socket(const Socket &ref) : addr(ref.addr), port(ref.port)
{
	address = ref.address;
	sockfd = ref.sockfd;
}

Socket&		Socket::operator=(const Socket& ref)
{
	addr = ref.addr;
	port = ref.port;
	sockfd = ref.sockfd;
	address = ref.address;
	return *this;
}

void	Socket::set_socket()
{
	std::string ip = get_string_ip_from_addr(addr);

	std::cout << DEFAULT << "Creating socket " << ip << ":" << port << ": "<< DEFAULT ;

	std::cout << RED;

	if ((sockfd = socket(AF_INET, SOCK_STREAM | SOCK_CLOEXEC, 0)) == -1)
		throw(SocketException("socket system call: "));

	const int enable = 1;
	if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0)
		throw(SocketException("setsockopt call: "));
	
	memset(&address, 0, sizeof(address));
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = htonl(addr);
	address.sin_port = htons(port);

	if (bind(sockfd, (struct sockaddr *)&address, sizeof(address)) < 0)
		throw(SocketException("bind system call: "));


	if (listen(sockfd, 20) < 0)
		throw(SocketException("listen system call: "));

	std::cout << GREEN << "as fd: " << sockfd << DEFAULT << '\n';
}


Socket::~Socket()
{
	if (sockfd != -1)
	{
		std::cout << RED << "Closing socket with fd: " << sockfd << DEFAULT << '\n';
		if (close(sockfd) == -1)
			std::cerr << "close system call: " << strerror(errno) << '\n';
	}
}

int	Socket::get_sockfd() const
{
	return sockfd;
}

bool	arr_Socket::is_in_the_array(int fd)
{
	for (size_t i = 0; i < size(); i++)
	{
		if (this->operator[](i).get_sockfd() == fd)
			return 1;
	}
	return 0;
}

Socket::SocketException::SocketException(std::string hehe)
{
	str = hehe + strerror(errno);
}

char const * Socket::SocketException::what() const throw()
{
	return str.c_str();
}

Socket::SocketException::~SocketException() throw(){}