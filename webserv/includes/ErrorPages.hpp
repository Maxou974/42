#ifndef ERROR_PAGE_HPP
#define ERROR_PAGE_HPP

#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#include <string>
#include <iostream>
#include <unistd.h>
#include <exception>
#include <fcntl.h>

#include "StatusCode.hpp"

class ErrorPages{

	std::vector<std::string>	vect;
	std::map<int, int>			map;

public:
	ErrorPages();
	ErrorPages(const ErrorPages &ref);
	ErrorPages& operator=(const ErrorPages &ref);
	~ErrorPages();

	void	add_error_pages(const int code, const std::string &str);
	const std::string	get_path(const int code) const;

	void	show() const;


};

std::string	get_default_error_pages(const int code);

#endif