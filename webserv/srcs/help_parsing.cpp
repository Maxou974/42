#include "Server.hpp"
#include "Parsing.hpp"
#include "Location.hpp"


std::string server_directive[SERVER_DIRECTIVE_NBR] = \
{ "server_name", "root", "listen", "location", "allow_method", "error_page"\
	, "autoindex", "client_max_body_size", "return", "upload_dir", "index" };

std::string location_directive[LOCATION_DIRECTIVE_NBR] = \
{ "allow_method", "index", "alias", "return", "autoindex", "upload_dir"\
	, "cgi_extension" };


int	count_line(const std::string &str, size_t to)
{
	size_t i = 0;
	int ret = 1;
	while (i < to && i < str.size())
		if (str[i++] == '\n')
			ret++;
	return ret;
}

void	skip_space(const std::string &str, size_t &beg)
{
	while( beg < str.size() && isspace(str[beg]) )
		beg++;
}

size_t	get_next_space_index(const std::string &str, size_t from)
{
	while (from < str.size() && !isspace(str[from]) )
		from++;
	return from;
}

size_t	get_semicolon_index(const std::string& str, size_t from)
{
	while(from < str.size() && str[from] != ';')
		from++;
	return from;
}

size_t	get_next_close_bracket( const std::string &str, size_t from)
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
	std::cerr << "Syntax error, can't recognize: " \
	<< t << " | at line : " << line << std::endl;
}

// check for three '.' and if there is only digit in host
bool	check_host(const std::string &str)
{
	int	n_dots = 0;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] == '.')
			n_dots++;
		else if (!isdigit(str[i]))
			return 1;
	}
	if (n_dots != 3)
		return 1;
	return 0;
}

static std::string trim_host(const std::string &str, int j)
{
	int n_dots = 0;
	int first = 0;
	int last;
	for (size_t i = 0; i < str.size() && n_dots != j; i++)
	{
		if (str[i] == '.')
			n_dots++;
		first = i + 1;
	}

	for (size_t i = first; i < str.size() && str[i] != '.'; i++)
		last = i;

	return std::string(str, first, last - first + 1);

}

int64_t	get_host_value(const std::string &str)
{
	int64_t ret = 0;
	for (int i = 0; i < 4; i++)
	{
		std::string tmp = trim_host(str, i);

		for (size_t j = 0; j < tmp.size(); j++)
			if (!isdigit(tmp[j]) || tmp.size() > 3)
				return -1;

		int64_t int_tmp = static_cast<int64_t>(std::atoi(tmp.c_str()));
		if (int_tmp > 255 || int_tmp < 0)
			return -1;

		if (i == 0)
			int_tmp = int_tmp << 24;
		if (i == 1)
			int_tmp = int_tmp << 16;
		if (i == 2)
			int_tmp = int_tmp << 8;

		ret = ret | int_tmp;
	}
	return ret;
}

int32_t	get_port_value(const std::string &str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!isdigit(str[i]))
			return -1;
	}

	if (str.size() > 5)
		return -1;

	return static_cast<int32_t>(std::atoi(str.c_str()));
}

std::vector<std::string> parse_value(const std::string& value)
{
	std::vector<std::string> vec;
	size_t i, j;
	
	for (i = 0; i < value.size(); )
	{
		skip_space(value, i);
		j = get_next_space_index(value, i);
		if (j - i > 0)
			vec.push_back(std::string(value, i, j - i));
		i = j;
	}

	return vec;
}

