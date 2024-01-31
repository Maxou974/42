#include "CGI.hpp"

CGI::CGI()
{
	is_child_launched = false;
	child_exited = false;
	cgi_complete = false;
	cgi_error = false;
	is_init = false;
	error_code = 0;
}

void	CGI::init(const Server& serv, Request& request, methd meth)
{
	is_init = true;
	this->msg_vector = request.get_body();
	is_child_launched = false;
	child_exited = false;
	cgi_complete = false;
	cgi_error = false;
	read_returned_zero = false;
	method = meth;
	content_length = msg_vector.size();
	bytes_wrote = 0;
	pipe_stdin[0] = -1;
	pipe_stdout[1] = -1;
	pipe_stdout[0] = -1;
	pipe_stdin[1] = -1;
	if (meth == POST)
	{
		add_env("REQUEST_METHOD", "POST");
		add_env("CONTENT_LENGTH", int_to_string(content_length));
		add_env("CONTENT_TYPE", request.get_header_value_from_key("Content-Type"));
	}
	if (meth == GET)
	{
		add_env("REQUEST_METHOD", "GET");
		add_env("QUERY_STRING", request.get_query_string());
	}

	add_env("SERVER_PROTOCOL", "HTTP/1.1");
	add_env("REQUEST_TIME", int_to_string(time(NULL)));
	add_env("REDIRECT_STATUS", "200");

	const Location& loc = serv.get_location()[get_location_index(serv, request.get_uri())];
	
	cgi_path = loc.get_cgi_path();

	std::string trim_uri = request.get_uri();

	file_name = loc.get_alias() + trim_uri.erase(0, loc.get_path().size());

	add_env("PATH_INFO", file_name);
	add_env("SCRIPT_FILENAME", file_name);
}

int	CGI::process(std::vector<unsigned char>& body)
{
	if (cgi_complete && cgi_error)
		return 500;
	if (cgi_complete && !cgi_error)
		return 200;

	errno = 0;
	int ret_access = access(file_name.c_str(), F_OK);
	if (errno == ENOENT)
		return 404;
	if (ret_access == -1)
		return 500;

	if (is_child_launched == false)
	{
		try{
			first_call();
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << '\n';
			return cgi_set_error(error_code);
		}
	}
	else
	{
		if (!does_child_exited())
		{	
			try {
				check_if_child_exited();
				write_read_pipe_to_body(body);
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << ": " << strerror(errno) << '\n';
				return cgi_set_error(error_code);
			}
		}
		else
		{
			if (!read_is_finish())
			{
				try
				{
					write_read_pipe_to_body(body);
				}
				catch (std::exception &e)
				{
					std::cerr << e.what() << '\n';
					return cgi_set_error(error_code);
				}
			}
			else
			{
				cgi_complete = true;
				return 200;
			}
		}
	}
	return 0;
}

CGI::CGI(const CGI &ref) : msg_vector(ref.msg_vector)
{
	env_vector = ref.env_vector;
	string_vector = ref.string_vector;

	is_child_launched = ref.is_child_launched;
	child_exited = ref.child_exited;
	cgi_error = ref.cgi_error;
	read_returned_zero = ref.read_returned_zero;
	pipe_stdin[0] = ref.pipe_stdin[0];
	pipe_stdin[1] = ref.pipe_stdin[1];
	pipe_stdout[0] = ref.pipe_stdout[0];
	pipe_stdout[1] = ref.pipe_stdout[1];
	pid = ref.pid;
	start_time = ref.start_time;

	cgi_path = ref.cgi_path;
	file_name = ref.file_name;
	method = ref.method;
	content_length = ref.content_length;
	bytes_wrote = ref.bytes_wrote;
	error_code = ref.error_code;

	cgi_complete = ref.cgi_complete;
	is_init = ref.is_init;
}

CGI&	CGI::operator=(const CGI &ref)
{
	env_vector = ref.env_vector;
	string_vector = ref.string_vector;

	is_child_launched = ref.is_child_launched;
	child_exited = ref.child_exited;
	cgi_error = ref.cgi_error;
	read_returned_zero = ref.read_returned_zero;
	pipe_stdin[0] = ref.pipe_stdin[0];
	pipe_stdin[1] = ref.pipe_stdin[1];
	pipe_stdout[0] = ref.pipe_stdout[0];
	pipe_stdout[1] = ref.pipe_stdout[1];
	pid = ref.pid;
	start_time = ref.start_time;

	cgi_path = ref.cgi_path;
	file_name = ref.file_name;
	method = ref.method;
	content_length = ref.content_length;
	bytes_wrote = ref.bytes_wrote;
	error_code = ref.error_code;


	cgi_complete = ref.cgi_complete;
	is_init = ref.is_init;
	return *this;
}

CGI::~CGI()
{
	clear_env();
}

void	CGI::add_env(const std::string& key, const std::string& value)
{
	string_vector.push_back(key + "=" + value);
}

void	CGI::clear_env()
{
	size_t i = 0;
	while ( i < env_vector.size() && env_vector[i])
		free(env_vector[i++]);

	env_vector.clear();
	string_vector.clear();
}

void	CGI::build_env()
{
	env_vector.clear();
	for(size_t i = 0; i < string_vector.size(); i++)
	{
		char *tmp = strdup(string_vector[i].c_str());

		if (tmp == NULL)
			exit(1);
		env_vector.push_back( strdup(string_vector[i].c_str()) );
	}
	env_vector.push_back(0);
}

void	CGI::init_pipe()
{
	if (method == POST && content_length > 0)
	{
		if ( pipe(pipe_stdin) == -1 )
		{
			error_code = 500;
			throw(std::runtime_error("pipe stdin error: "));
		}
	}

	if ( pipe(pipe_stdout) == -1 )
	{
		close_all_pipe();
		error_code = 500;
		throw(std::runtime_error("pipe stdout error: "));
	}
}

void	CGI::first_call()
{
	init_pipe();

	start_time = time(NULL);

	pid = fork();

	if (pid == -1)
	{
		close_all_pipe();
		error_code = 500;
		throw(std::runtime_error("fork error: "));
	}
	else if (pid == 0)
	{
		if (method == POST && content_length > 0)
			if ( dup2(pipe_stdin[0], STDIN_FILENO) == -1 )
			{
				std::cerr << "dup2 stdin error: " << strerror(errno) << '\n';
				exit(1);
			}

		if ( dup2(pipe_stdout[1], 1) == -1 )
		{
			std::cerr << "dup2 stdout error: " << strerror(errno) << '\n';
			exit(1);
		}
		if (method == POST && content_length > 0)
		{
			close_pipe(pipe_stdin[0]);
			close_pipe(pipe_stdin[1]);
		}
		close_pipe(pipe_stdout[0]);
		close_pipe(pipe_stdout[1]);

		char *arg[] = { strdup(cgi_path.c_str()), strdup( file_name.c_str() ), 0 };

		build_env();
		if (arg[0] == NULL || arg[1] == NULL)
		{
			std::cerr << "strdup error while building char *arg[] for cgi\n";
			exit(1);
		}

		execve(arg[0], arg, env_vector.data());

		free(arg[0]);
		free(arg[1]);
		clear_env();
		exit(1);
	}
	else
	{
		close_pipe(pipe_stdout[1]);

		if (method == POST && content_length > 0)
		{
			close_pipe(pipe_stdin[0]);
			if ( fcntl(pipe_stdin[1], F_SETFL, O_NONBLOCK) == -1 )
			{
				close_all_pipe();
				error_code = 500;
				throw(std::runtime_error("fctnl stdin pipe error: "));
			}
		}
		
		if ( fcntl(pipe_stdout[0], F_SETFL, O_NONBLOCK) == -1 )
		{
			close_all_pipe();
			error_code = 500;
			throw(std::runtime_error("fctnl stdour pipe error: "));
		}
	}
	is_child_launched = true;
}

void	CGI::check_if_child_exited()
{
	if ( (time(NULL) - start_time) > CHILD_TIMEOUT )
	{
		kill(pid, SIGKILL);
		child_exited = true;
		close_all_pipe();
		error_code = 504;
		throw(std::runtime_error("child timeout: "));
	}
	int	wstatus;
	pid_t	wait_ret = waitpid(pid, &wstatus, WNOHANG);

	if (wait_ret == -1)
	{
		close_all_pipe();
		error_code = 500;
		throw(std::runtime_error("waitpid error: "));
	}

	if ( wait_ret > 0 && WIFEXITED(wstatus) )
	{
		child_exited = true;
		std::cerr << "cgi child exited with code: " << WEXITSTATUS(wstatus) << "\n";
		if (WEXITSTATUS(wstatus) != 0)
		{
			close_all_pipe();
			error_code = 500;
			throw(std::runtime_error("exit status error: "));
		}
	}
}

void		CGI::write_read_pipe_to_body(std::vector<unsigned char>& body)
{
	if (!child_exited && bytes_wrote < content_length)
	{
		struct timeval ti;
		ti.tv_sec = 0;
		ti.tv_usec = 10000;
		fd_set write_fd;
		FD_ZERO(&write_fd);
		FD_SET(pipe_stdin[1], &write_fd);

		int sel2 = select(pipe_stdin[1] + 1, 0, &write_fd, 0, &ti);

		if (sel2 == -1)
		{
			close_all_pipe();
			error_code = 500;	
			throw(std::runtime_error("write select error: "));;
		}
		else if (sel2 == 1)
		{
			ssize_t ret = write(pipe_stdin[1], msg_vector.data() + bytes_wrote, msg_vector.size() - bytes_wrote);
	
			if (ret == -1)
			{
				close_all_pipe();
				error_code = 500;
				throw(std::runtime_error("write error: "));;
			}
			bytes_wrote += ret;
		}
	}
	else
	{
		if (method == POST && content_length > 0 && pipe_stdin[1] != -1)
		{
			close_pipe(pipe_stdin[1]);
		}
	}

	if (read_returned_zero == false)
	{
		struct timeval ti;
		ti.tv_sec = 0;
		ti.tv_usec = 1000;
		fd_set read_fd;
		FD_ZERO(&read_fd);
		FD_SET(pipe_stdout[0], &read_fd);

		int sel = select(pipe_stdout[0] + 1, &read_fd, 0, 0, &ti);

		if (sel == -1)
		{
			close_all_pipe();
			error_code = 500;
			throw(std::runtime_error("read select error: "));
		}
		else if (sel == 1)
		{
			char buffer[66000];
			ssize_t re = read(pipe_stdout[0], buffer, 66000);
			if (re == 0)
			{
				read_returned_zero = true;
				close_pipe(pipe_stdout[0]);
				return;
			}
			if (re == -1)
			{
				close_all_pipe();
				error_code = 500;
				throw(std::runtime_error("cgi read error: "));
			}
			for (ssize_t i = 0; i < re; i++)
				body.push_back(buffer[i]);
		}
	}
}

bool	CGI::does_child_exited() const
{ return child_exited; }

bool	CGI::child_is_launched() const
{ return is_child_launched; }

bool	CGI::read_is_finish() const
{ return read_returned_zero; }

int	CGI::cgi_set_error(const int code)
{
	cgi_complete = true;
	cgi_error = true;
	return code;
}

void	CGI::close_pipe(int& pipe)
{
	if (pipe != -1)
		close(pipe);
	pipe = -1;
}

void	CGI::close_all_pipe()
{
	close_pipe(pipe_stdin[0]);
	close_pipe(pipe_stdin[1]);
	close_pipe(pipe_stdout[0]);
	close_pipe(pipe_stdout[1]);
}