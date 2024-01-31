#ifndef REQUEST_HPP
#define REQUEST_HPP

#include <vector>
#include <string>
#include <iostream>
#include <cctype>
#include <stdexcept>
#include <exception>
#include <map>

#include "webserv_utility.h"

typedef	const std::vector<unsigned char> const_uchar_vector;
typedef	std::vector<unsigned char> uchar_vector;

class Request{

	std::vector<unsigned char>	raw_request_vector;
	std::map<std::string, std::string>	header_map;

	std::string uri;
	std::string	query_string;
	std::string method;
	std::string protocol;

public:
	bool request_is_complete;
	bool header_is_complete;

	Request();
	Request(const Request &ref);
	Request& operator=(const Request &ref);
	~Request();

	void	concatenate_request(const char *buffer, size_t buffer_size);
	int		parse_request();
	int		parse_request_body(const size_t max_body_size);
	void	parse_request_header();
	void	parse_request_line(const std::string& request_line);
	void    add_header_in_map(const std::string &str);

	std::string	get_header_value_from_key(const std::string &key) const;
	std::string	get_uri() const;
	std::string	get_query_string() const;
	std::string get_method() const;
	std::string get_host() const;
	uchar_vector& get_body();


};



#endif