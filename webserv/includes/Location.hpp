#ifndef LOCATION_HPP
#define LOCATION_HPP

#include "Server.hpp"
#include "Parsing.hpp"
#include <exception>
#include <utility>
#include <algorithm>

#define LOCATION_DIRECTIVE_NBR 7
#define SSERROR Server::ServerSyntaxError
class Server;

class Location
{
	typedef	void( Location::*fct_ptr )( const std::string & );
	fct_ptr	location_ptrs[LOCATION_DIRECTIVE_NBR];

	int 						method; //method will be used with bitshifting 1st bit -> GET 2nd bit -> POST 3rd bit -> DELETE
	std::string 				path;
	std::string 				redirection;
	std::vector<std::string> 	index;
	std::string 				alias;
	bool						autoindex_is_on;
	std::string					upload_dir;
	std::string					cgi_extension;
	std::string					cgi_path;
	size_t						line;

public:
	Location();
	Location(const Location &);
	Location& operator=(const Location &);
	~Location();

	void							set_index(const std::string& value);
	void							set_alias(const std::string& value);
	void							set_autoindex(const std::string& value);
	void							set_uploaddir(const std::string& value);
	void							set_methods( const std::string& value );
	void							set_redirection(const std::string& value);
	void							set_cgiextension(const std::string& value);
	std::pair<std::string, size_t>	set( const std::string& str, size_t li );
	void							show();

	const std::string& 				get_path() const;
	const std::string& 				get_redirection() const;
	const std::vector<std::string>&	get_index() const;
	const std::string& 				get_alias() const;
	const bool&						is_autoindex_on() const;
	const std::string& 				get_upload_dir() const;
	const std::string& 				get_cgi_extension() const;
	const std::string& 				get_cgi_path() const;

	bool				get_is_allowed()const;
	bool				post_is_allowed()const;
	bool				delete_is_allowed()const;

};

#endif