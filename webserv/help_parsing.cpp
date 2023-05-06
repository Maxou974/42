#include "Server.hpp"
#include "Parsing.hpp"


std::string server_directive[SERVER_DIRECTIVE_NBR] = \
{ "server_name", "root", "listen", "location", "allow_method" };


std::string location_directive[LOCATION_DIRECTIVE_NBR] = \
{ "allow_method", "index", "alias", "return", "autoindex", "upload_dir" };



int	count_line(const std::string &str, int to)
{
	int i = 0;
	int ret = 1;
	while (i < to && i < str.size())
		if (str[i++] == '\n')
			ret++;
	return ret;
}

void	skip_space(const std::string &str, int &beg)
{
	while( beg < str.size() && isspace(str[beg]) )
		beg++;
}

int	get_next_space_index(const std::string &str, int from)
{
	while (from < str.size() && !isspace(str[from]) )
		from++;
	return from;
}

int	get_semicolon_index(const std::string& str, int from)
{
	while(from < str.size() && str[from] != ';')
		from++;
	return from;
}

int	get_next_close_bracket( const std::string &str, int from)
{
	while(from < str.size() && str[from] != '}')
		from++;
	return from;
}

int	directive_index(const std::string *tab, int tab_size, const std::string &str)
{
	int	i = 0;
	while (i < tab_size)
	{
		if (str == tab[i])
			return i;
		i++;
	}
	return -1;
}

void	syntax_error(const char *t, const int line)
{
	std::cout << "Syntax error, can't recognize: " \
	<< t << " | at line : " << line << std::endl;
}