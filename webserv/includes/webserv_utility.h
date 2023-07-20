#ifndef WEBSER_UTILITY_
#define WEBSER_UTILITY_

#include <cstring>
#include <iostream>
#include <time.h>
#include <sstream>
#include <vector>

#define RESPONSE_FORM "%a, %d %b %Y %k:%M:%S GMT"
#define INFO_FORM "[%x %X]"

template <class T>
std::string	int_to_string(const T n)
{
	std::ostringstream convert;
	convert << n;
	return convert.str();
}

template<class T>
void write_string_to_vector(const std::string str, std::vector<T> &vec)
{
	for (size_t i = 0; i < str.size(); i++)
		vec.push_back(str[i]);
}

std::string	get_gmt_time(const char *format, time_t ti);
std::string	get_string_ip_from_addr(const unsigned long addr);
std::string	timer();
size_t	string_to_size_t(const std::string& str);
size_t	find_string_in_vector(const std::vector<unsigned char>& vec, const std::string& str);
size_t	find_string_in_vector(const std::vector<unsigned char>& vec, size_t pos, const std::string& str);

#endif