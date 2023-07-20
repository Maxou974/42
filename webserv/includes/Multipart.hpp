#ifndef MULTIPART_HPP
#define MULTIPART_HPP

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
#include <fcntl.h>
#include <unistd.h>

#include "webserv_utility.h"

struct info
{
	size_t 		start_data;
	size_t 		end_data;
	std::string file_name;
};


class Multipart{

	std::string 				boundary;
	std::vector<unsigned char>&	body;
	std::vector< std::pair<size_t, size_t> > index;

	Multipart();
	Multipart(const Multipart &);
	Multipart& operator=(const Multipart &);

public:
	std::vector<struct info> info_vector;
	Multipart(const std::string &ContentTypeValue, std::vector<unsigned char>& request_body);
	~Multipart();

	void	set_index_vector();
	bool	boundary_match(size_t start);
	// void	show_trimed();
	int		set_info_vector();
	// void	show_info_vector();






};

#endif