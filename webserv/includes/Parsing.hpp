#ifndef PARSING_H
#define PARSING_H

#include <cstring>

extern std::string 					server_directive[];
extern std::string 					location_directive[];


int		count_line(const std::string &str, size_t to);
void	skip_space(const std::string &str, size_t &beg);
size_t	get_next_space_index(const std::string &str, size_t from);
size_t	get_semicolon_index(const std::string& str, size_t from);
size_t	get_next_close_bracket( const std::string &str, size_t from);

int		directive_index(const std::string *tab, int tab_size, const std::string &str);
void	syntax_error(const char *t, const int line);


bool	check_host(const std::string &str);
int64_t	get_host_value(const std::string &str);
int32_t	get_port_value(const std::string &str);

std::vector<std::string> parse_value(const std::string& value);


#endif