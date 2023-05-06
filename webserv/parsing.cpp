#include "Server.hpp"
#include "Parsing.hpp"


int	parsing(std::fstream &conf_file, std::vector<Server>& server_vect)
{
	char 	str[256];
	int		n_brackets = 0;
	int		n_server = 0;

	//get all file in one string and close it;
	std::string file;
	while (conf_file.eof() == false)
	{
		conf_file.getline(str, 256);
		file.append(str);
		file.push_back('\n');
	}
	conf_file.close();

	// std::cout << file;
	
	int i = 0;

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
					syntax_error(key.c_str(), count_line(file, i));
					return 1;
				}
				else
				{
					try{
						server_vect[n_server].init(dir_index, value);
					}
					catch(...)
					{
						syntax_error("location block", count_line(file, i)); return 1;
					}
				
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

	std::vector<Server> server_vect;

	if (argc != 2)
	{
		std::cout << "one conf file needed\n";
		return 1;
	}

	std::fstream conf_file(argv[1], std::fstream::in);

	if (conf_file.is_open() == false)
	{
		std::cout << "cannot open conf file\n";
		return 1;
	}

	if (parsing(conf_file, server_vect))
		return 1;

	for (int i = 0; i < server_vect.size(); i++)
		server_vect[i].show();


}