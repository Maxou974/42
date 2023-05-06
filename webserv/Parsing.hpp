#ifndef PARSING_H
#define PARSING_H

#include <string>

extern std::string server_directive[];
extern std::string location_directive[];

int		count_line(const std::string &str, int to);
void	skip_space(const std::string &str, int &beg);
int		get_next_space_index(const std::string &str, int from);
int		get_semicolon_index(const std::string& str, int from);
int		get_next_close_bracket( const std::string &str, int from);

int		directive_index(const std::string *tab, int tab_size, const std::string &str);
void	syntax_error(const char *t, const int line);


#endif