#ifndef LOCATION_HPP
#define LOCATION_HPP

#include "Server.hpp"
#include "Parsing.hpp"
#include <exception>

#define LOCATION_DIRECTIVE_NBR 6

class Location
{
	typedef	void( Location::*fct_ptr )( const std::string );
	fct_ptr	location_ptrs[LOCATION_DIRECTIVE_NBR];

	int 		method;
	//method will be used with bitshifting 1st bit -> GET 2nd bit -> POST 3rd bit -> DELETE
	std::string path;
	std::string index;
	std::string alias;
	std::string ret;
	bool		bool_autoindex;
	std::string	upload_dir;

public:
	Location(){
		location_ptrs[0] = &Location::set_methods;
		location_ptrs[1] = &Location::set_index;
		location_ptrs[2] = &Location::set_alias;
		location_ptrs[3] = &Location::set_ret;
		location_ptrs[4] = &Location::set_autoindex;
		location_ptrs[5] = &Location::set_uploaddir;
		method = 1; index = ""; alias = ""; ret = ""; upload_dir = ""; bool_autoindex = false;
	}

	void	set_index(const std::string value)
	{
		index = value;
	}

	void	set_alias(const std::string value)
	{
		alias = value;
	}

	void	set_ret(const std::string value)
	{
		ret = value;
	}

	void	set_autoindex(const std::string value)
	{
		if (value == "on")
			bool_autoindex = true;
	}

	void	set_uploaddir(const std::string value)
	{
		upload_dir = value;
	}

	void	set_methods( const std::string value ){
		method = 0;
		if (value.find("GET") != std::string::npos)
			method += 1;
		if (value.find("POST") != std::string::npos)
			method += 2;
		if (value.find("DELETE") != std::string::npos)
			method += 4;
	}

	void	set( const std::string& str )
	{
		int i = 0;
		skip_space(str, i);
		int j = i;
		while (!isspace(str[j]) && str[j] != '{')
			j++;
		path.assign(str, i, j - i);
		i = j;
		skip_space(str, i);
		if (str[i] != '{')
			throw(std::exception());
		
		i++;
		while (i < str.size() && str[i] != '}')
		{
			skip_space(str, i);
			j = get_next_space_index(str, i);
			std::string key(str, i, j - i);
			i = j;
			
			skip_space(str, i);
			
			std::string value(str, i, get_semicolon_index(str, i) - i);
			
			int dir_index = directive_index(location_directive, LOCATION_DIRECTIVE_NBR, key);
			if (dir_index < 0)
				throw(std::exception());
			else
				(this->*location_ptrs[dir_index])(value);


			i = get_semicolon_index(str, i) + 1;
			skip_space(str, i);
		}
		if (str[i] != '}' || i != str.size() - 1)
			throw(std::exception());
	}

	void	show()
	{
		std::cout << "\n\tLOCATION: ";
		std::cout << path << '\n';
		std::cout << "\tindex: " << index << '\n';
		std::cout << "\talias: " << alias << '\n';
		std::cout << "\tret: " << ret << '\n';
		std::cout << "\tautoindex: " << bool_autoindex << '\n';
		std::cout << "\tupload_dir: " << upload_dir << '\n';
		std::cout << "\tmethod: " << method << '\n';
		std::cout << "\tEND LOCATION: " << path << '\n';

	}

};



#endif