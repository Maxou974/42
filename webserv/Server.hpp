#ifndef SERVER_HPP
#define SERVER_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include <cstdlib>

#include "Location.hpp"
#include "Parsing.hpp"

#define SERVER_DIRECTIVE_NBR 5

class Server
{
	typedef	void( Server::*fct_ptr )( const std::string );
	fct_ptr	server_ptrs[SERVER_DIRECTIVE_NBR];

	std::string server_name;
	std::string root;
	std::string host_port;
	std::vector<Location> location;
	
	public:
	Server()
	{
		server_ptrs[0] = &Server::set_server_name;
		server_ptrs[1] = &Server::set_root;
		server_ptrs[2] = &Server::set_host_port;
		server_ptrs[3] = &Server::set_location;
		server_ptrs[4] = &Server::set_methods;

		server_name = "localhost";
	}

	void	init(int dir_index, const std::string value)
	{
		// std::cout << "init: " << dir_index << "  " << value << '\n';
		(this->*server_ptrs[dir_index])(value);
	}

	void set_server_name(const std::string value)
	{ server_name = value; }
	
	void set_location(const std::string value)
	{
		Location tmp;
		tmp.set(value);
		location.push_back(tmp);
	}

	void set_host_port(const std::string value)
	{ host_port = value; }

	void set_root(const std::string value)
	{ root = value; }

	void set_methods(const std::string value)
	{

	}


	void	show()
	{ 
		std::cout << "\nSERVER\n";
		std::cout << " server_name:" << server_name << '\n';
		std::cout << " host_port:" << host_port << '\n';
		std::cout << " root:" << root << '\n';

		for (int i = 0; i < location.size(); i++)
			location[i].show();
		std::cout << "ENDSERVER\n";
	}
};






#endif
