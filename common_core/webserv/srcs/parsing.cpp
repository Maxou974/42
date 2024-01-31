#include "Server.hpp"
#include "Parsing.hpp"
#include "Socket.hpp"
#include "Client.hpp"
#include "Select.hpp"
#include "ErrorPages.hpp"
#include "MIME.hpp"

int	parsing(std::fstream &conf_file, std::vector<Server>& server_vect)
{
	char 	str[512];
	int		n_brackets = 0;
	int		n_server = 0;
	//get all file in one string and close it;
	std::string file;
	while (conf_file.eof() == false)
	{
		if (conf_file.bad() || conf_file.fail())
		{
			conf_file.close();
			throw(std::runtime_error("Error while reading conf file"));
		}
		conf_file.getline(str, 512);
		file.append(str);
		file.push_back('\n');
	}

	conf_file.close();

	size_t i = 0;

	while (i < file.size() )
	{
	//	search for server block if not inside server block
		if (n_brackets == 0)
		{
			skip_space(file, i);

			if (i == file.size())
				break;

			std::string tmp(file, i, 6);
			if (tmp != "server")
			{
				syntax_error(tmp.c_str(), count_line(file, i));
				return 1;
			}
			else
				i += 6;

			skip_space(file, i);

			if (file[i] != '{')
			{
				syntax_error("Missing opening '{'", count_line(file, i));
				return 1;
			}
			else
			{
				n_brackets++;
				i++;
			}
		}
		else
		{
		//parse inside server_block
			server_vect.resize(server_vect.size() + 1);
			while( file[i] != '}' )
			{
				skip_space(file, i);

				int	next_space_index = get_next_space_index(file, i);
				std::string key(file, i, next_space_index - i);
				i = next_space_index;
				
				skip_space(file, i);
				
				std::string value;
				if (key == "location")
					value.assign(file, i, get_semicolon_index(file, get_next_close_bracket(file, i)) - i);
				else
					value.assign(file, i, get_semicolon_index(file, i) - i);

				int dir_index = directive_index(server_directive, SERVER_DIRECTIVE_NBR, key);
				if ( dir_index < 0 )
				{
					throw(Server::ServerSyntaxError(key.c_str(), count_line(file, i - 1) ));
					return 1;
				}
				else
				{
					server_vect[n_server].init(dir_index, value, count_line(file, i - 1 ) );
				}
				if (key == "location")
					i = get_next_close_bracket(file, i) + 1;
				i = get_semicolon_index(file, i) + 1;
				skip_space(file, i);
			}
			n_brackets--;
			n_server++;
			i++;
		}
	}
	return 0;
}


int main(int argc, char **argv)
{

	arr_Server server_vect;
	arr_Socket socket_arr;

	if (argc != 2)
	{
		std::cerr << "One conf file needed\n";
		return 1;
	}

	std::fstream conf_file(argv[1], std::fstream::in);

	if (conf_file.is_open() == false)
	{
		std::cerr << "Cannot open conf file\n" << strerror(errno) << '\n';
		return 1;
	}

	try
	{
		int ret = parsing(conf_file, server_vect);
		
		if (ret)
			return 1;
		
		if (server_vect.size() == 0)
		{
			std::cerr << "No server to handle\n";
			return 1;
		}

		socketing(server_vect, socket_arr);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << DEFAULT << '\n';
		return 1;
	}

	call_select(server_vect,socket_arr);
	
}