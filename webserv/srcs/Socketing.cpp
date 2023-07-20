#include "Server.hpp"
#include "Socket.hpp"

/*
	Here we parsed all the conf file and know all the IP and port to bind
	We need to:
		- take all IP and port
		- if there is a IP set to zero ->	remove all the other that are 
											on the same port
		- remove all the duplicate IP for the same port
		- create the socket object
*/


void	socketing(arr_Server &server_v, arr_Socket &socket_v)
{
	(void)socket_v;
	std::map< unsigned short, std::vector<unsigned long> > map;
	std::vector<Server>::iterator it;

	for (it = server_v.begin(); it != server_v.end(); it++)
		map[it->get_port_host_order()].push_back(it->get_addr_host_order());

	std::map< unsigned short, std::vector<unsigned long> >::iterator i;
	std::vector<unsigned long>::iterator vec_it;
	
	for (i = map.begin(); i != map.end(); i++)
	{
		std::vector<unsigned long> & ref = i->second;
		vec_it = std::find(ref.begin(), ref.end(), 0);
		if (vec_it != ref.end())
		{ ref.clear(); ref.push_back(0); } // remove all and let 0, if there is a 0
		else // if there is no 0, remove all duplicate
		{
			std::vector<unsigned long>::iterator vec_it2;
			for (vec_it2 = ref.begin(); vec_it2 != ref.end(); vec_it2++)
			{
				for (vec_it = vec_it2 + 1; vec_it != ref.end(); vec_it++)
				{
					if (*vec_it == *vec_it2)
					{
						ref.erase(vec_it);
						vec_it = vec_it2;
					}
				}
			}
		}
	}

	/* Here in map we have all the IP and port to create socket*/
	for (i = map.begin(); i != map.end(); i++)
	{
		std::vector<unsigned long> & ref = i->second;
		for (vec_it = ref.begin(); vec_it != ref.end(); vec_it++)
			socket_v.push_back(Socket(*vec_it, i->first));
	}

	for (size_t ii = 0; ii < socket_v.size(); ii++)
		socket_v[ii].set_socket();

}