#ifndef RESPONSE_HPP
#define RESPONSE_HPP

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include <unistd.h>

#include "chunked-transfer.h"
#include "webserv_utility.h"
#include "autoindex.h"
#include "ErrorPages.hpp"
#include "StatusCode.hpp"
#include "MIME.hpp"
#include "Server.hpp"
#include "Request.hpp"

#define MIN_FILE_SIZE_FOR_CHUNKED 5000000
#define CHUNKED_REQUEST_BUFFER_SIZE 1000000

class Response {

	std::string					status;
	std::vector<std::string>	header;
	ssize_t						bytes_wrote;
	bool						is_chunked;
	int							fd_chunked;
	bool						is_first_chunk_call;

public:
	std::vector<unsigned char>	body;
	std::vector<unsigned char>	response;

	Response();
	Response(const Response &);
	Response& operator=(const Response &);
	~Response();

	void	set_status_line(const std::string& str);
	void	set_status_line(const int code);
	void	add_header(const std::string& full_header);
	void	add_header(const std::string &field, const std::string& value);

	int		set_body_from_file(const std::string &path);

	void	build_autoindex(const std::string &full_path, const std::string &uri, const Server& serv);
	void	build_error(const ErrorPages& error_info, const int code);
	void	build_get(const Server &serv, const std::string& uri);
	void	build_post(const Server &serv, Request& request);
	void	build_delete(const Server &serv, Request& request);
	void	build_redirect(const int code, const std::string &location);

	const unsigned char *	get_Response() const;
	void					get_next_chunk(const ErrorPages &error_p);
	size_t					size() const;
	void					write_to_fd(const int fd);
	bool					is_fully_written() const;
	bool					is_chunked_() const;
	void					close_fd(int &fd);
	void					close_fd_chunked();

	void	set_body_if_file_set_redir_if_dir(const std::string& path, const std::string&uri ,const Server& serv);


	void				build();
	void				clear();
	
	void				show() const;

};

int		get_location_index(const Server &serv, const std::string& uri);


#endif