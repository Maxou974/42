#include "ServerResolver.hpp"

static std::vector<size_t>	search_exact_match_ip(const arr_Server& server_arr, const Client& cli)
{
	std::vector<size_t> vec;
	const unsigned long cli_addr = cli.get_addr();
	const unsigned short cli_port = cli.get_port();

	for (size_t i = 0; i < server_arr.size(); i++)
	{
		if (server_arr[i].get_port_host_order() == cli_port && 
			server_arr[i].get_addr_host_order() == cli_addr)
			vec.push_back(i);
	}
	return vec;
}

static std::vector<size_t>	search_port_match(const arr_Server& server_arr, const Client& cli)
{
	std::vector<size_t> vec;
	const unsigned short cli_port = cli.get_port();

	for (size_t i = 0; i < server_arr.size(); i++)
	{
		if (server_arr[i].get_port_host_order() == cli_port && 
			server_arr[i].get_addr_host_order() == 0)
			vec.push_back(i);
	}
	return vec;
}

//return the index of the server_name match if there is one, return the first index otherwise
static size_t	search_exact_server_name_match(std::vector<size_t>& index_arr,
							const arr_Server& server_arr, const Client& cli)
{
	for (size_t i = 0; i < index_arr.size(); i++)
	{
		if (cli.host_request == server_arr[index_arr[i]].get_server_name())
			return index_arr[i];
	}
	return index_arr[0];
}

const Server&		resolve_server(const arr_Server& server_arr, const Client& cli)
{
	std::vector<size_t> vec_index = search_exact_match_ip(server_arr, cli);

	if (vec_index.size() == 0) // then there is one or more 0.0.0.0
	{
		vec_index = search_port_match(server_arr, cli);
		if (vec_index.size() == 0)
			throw(std::runtime_error("No server to handle"));
		return server_arr[ search_exact_server_name_match(vec_index, server_arr, cli) ];
	}
	else if (vec_index.size() == 1) // then only one exact match
		return server_arr[vec_index[0]];
	else // multiple server match the exact ip 
		return server_arr[ search_exact_server_name_match(vec_index, server_arr, cli) ];
}