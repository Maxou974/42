#ifndef CGI_HPP
#define	CGI_HPP

#include <cstring>
#include <unistd.h>
#include <cstring>
#include <iostream>
#include <vector>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <cerrno>
#include <cstdlib>

#include "webserv_utility.h"
#include "Server.hpp"
#include "Response.hpp"
#include "Request.hpp"

#define CHILD_TIMEOUT 10

enum methd { GET, POST };

class CGI {

	std::vector<unsigned char> 	msg_vector;
	std::vector<char *> 		env_vector;
	std::vector<std::string>	string_vector;
	bool						is_child_launched;
	bool						child_exited;
	bool						cgi_error;
	bool						read_returned_zero;
	int							pipe_stdin[2], pipe_stdout[2];
	pid_t						pid;
	time_t						start_time;
	std::string					cgi_path;
	std::string					file_name;
	methd 	method;
	ssize_t content_length;
	ssize_t bytes_wrote;
	int		error_code;

public:
	bool	cgi_complete;
	bool	is_init;

	CGI();
	CGI(const CGI &ref);
	CGI&	operator=(const CGI &ref);
	~CGI();

	void	init(const Server& serv, Request& request, methd meth);
	int		process(std::vector<unsigned char>& body);

	void	add_env(const std::string& key, const std::string& value);

	void	build_env();
	void	clear_env();
	int		cgi_set_error(const int code);
	
	void	init_pipe();
	void	close_all_pipe();
	void	close_pipe(int& pipe);

	void	check_if_child_exited();

	void	first_call();
	void	write_read_pipe_to_body(std::vector<unsigned char>& body);

	bool	read_is_finish() const;
	bool	child_is_launched() const;
	bool	does_child_exited()	const;
};


#endif