#include "Location.hpp"


Location::Location(){
	location_ptrs[0] = &Location::set_methods;
	location_ptrs[1] = &Location::set_index;
	location_ptrs[2] = &Location::set_alias;
	location_ptrs[3] = &Location::set_redirection;
	location_ptrs[4] = &Location::set_autoindex;
	location_ptrs[5] = &Location::set_uploaddir;
	location_ptrs[6] = &Location::set_cgiextension;
	method = 1; alias = ""; redirection = "" ; upload_dir = ""; 
	autoindex_is_on = false; cgi_extension = ""; cgi_path = "";
 	index.push_back("index.html");
}

Location::Location(const Location &ref)
{
	*this = ref;
}
Location&	Location::operator=(const Location &ref)
{
	method = ref.method;
	path = ref.path;
	redirection = ref.redirection;
	index = ref.index;
	alias = ref.alias;
	autoindex_is_on = ref.autoindex_is_on;
	upload_dir = ref.upload_dir;
	line = ref.line;
	cgi_extension = ref.cgi_extension;
	cgi_path = ref.cgi_path;
	return *this;
}
Location::~Location(){}


void	Location::set_index(const std::string& value)
{
	index = parse_value(value);
	
	if (index.size() == 0)
		throw(SSERROR("index: invalid number of arg", line));
}
void	Location::set_alias(const std::string& value)
{
	std::vector<std::string> vec = parse_value(value);
	if (vec.size() != 1)
		throw(SSERROR("alias: invalid number of arg", line));
	alias = vec[0];
}
void	Location::set_autoindex(const std::string& value)
{
	std::vector<std::string> vec = parse_value(value);
	if (vec.size() != 1)
		throw(SSERROR("autoindex: invalid number of arg", line));
	if (vec[0] == "on")
		autoindex_is_on = true;
	else if (vec[0] == "off")
		autoindex_is_on = false;
	else
		throw(SSERROR("autoindex: invalid value (on | off)", line));
}
void	Location::set_uploaddir(const std::string& value)
{
	std::vector<std::string> vec = parse_value(value);
	if (vec.size() != 1)
		throw(SSERROR("upload_dir: invalid number of arg", line));
	upload_dir = vec[0];
}
void	Location::set_methods( const std::string& value ){
	std::vector<std::string> vec = parse_value(value);
	if (vec.size() > 3 || vec.size() == 0)
		throw(SSERROR("allow_method: invalid number of arg", line));
	
	if (1 < std::count(vec.begin(), vec.end(), "GET") ||
		1 < std::count(vec.begin(), vec.end(), "POST") ||
		1 < std::count(vec.begin(), vec.end(), "DELETE"))
		throw(SSERROR("allow_method: duplicate value not allowed", line));
	
	method = 0;
	for (size_t i = 0; i < vec.size(); i++)
	{
		if (vec[i] == "GET")
			method += 1;
		else if (vec[i] == "POST")
			method += 2;
		else if (vec[i] == "DELETE")
			method += 4;		
		else
			throw(SSERROR("allow_method: invalid value: " + vec[i], line));
	}
}

void	Location::set_redirection(const std::string &value)
{
	std::vector<std::string> vec = parse_value(value);
	if (vec.size() != 1)
		throw(SSERROR("return: invalid number of arg", line));
	redirection = vec[0];
}


void	Location::set_cgiextension(const std::string& value)
{
	std::vector<std::string> vec = parse_value(value);
		if (vec.size() != 2)
		throw(SSERROR("return: invalid number of arg", line));
	cgi_extension = vec[1];
	cgi_path = vec[0];
}

std::pair<std::string, size_t>	Location::set( const std::string& str, size_t li )
{
	line = li;
	size_t i = 0;
	skip_space(str, i);
	size_t j = i;
	while (!isspace(str[j]) && str[j] != '{')
		j++;
	path.assign(str, i, j - i);
	i = j;
	skip_space(str, i);
	if (str[i] != '{')
		return std::pair<std::string, size_t>("missing opening bracket", i);
	
	i++;
	while (i < str.size() && str[i] != '}')
	{
		skip_space(str, i);
		j = get_next_space_index(str, i);
		std::string key(str, i, j - i);
		i = j;
		
		skip_space(str, i);
		
		std::string value(str, i, get_semicolon_index(str, i) - i);
		
		int dir_index = directive_index(location_directive, LOCATION_DIRECTIVE_NBR, key);
		if (dir_index < 0)
			return std::pair<std::string, size_t>(key, i);
		else
		{
			line = li + count_line(str, i) - 1;
			(this->*location_ptrs[dir_index])(value);
		}
		i = get_semicolon_index(str, i) + 1;
		skip_space(str, i);
	}
	if (i != str.size() - 1)
		return std::pair<std::string, size_t>(";", i);
	if ( str[i] != '}' )
		return std::pair<std::string, size_t>("missing closing bracket", i);
	return std::pair<std::string, size_t>("no_error", 0);
}

const std::string&		Location::get_path() const
{ return path; }

const std::string&		Location::get_redirection() const
{ return redirection; }

const std::vector<std::string>&	Location::get_index() const
{ return index; }

const std::string&		Location::get_alias() const
{ return alias; }

const bool&		Location::is_autoindex_on() const
{ return autoindex_is_on; }

const std::string&		Location::get_upload_dir() const
{ return upload_dir; }

const std::string&		Location::get_cgi_extension() const
{ return cgi_extension; }

const std::string&		Location::get_cgi_path() const
{ return cgi_path; }

bool	Location::get_is_allowed() const
{
	return 0b1 & method;
}

bool	Location::post_is_allowed() const
{
	return 0b10 & method;
}

bool	Location::delete_is_allowed() const
{
	return 0b100 & method;
}

void	Location::show()
{
	std::cout << "\n\tLOCATION: ";
	std::cout << path << '\n';
	std::cout << "\tindex: ";
	if (index.size() == 0)
		std::cout << "EMPTY\n";
	else
		for(size_t i = 0; i < index.size(); i++)
			std::cout << "\t\t" << index[i] << '\n';
	std::cout << "\talias: " << alias << '\n';
	std::cout << "\treturn: " << redirection << '\n';
	std::cout << "\tautoindex: " << autoindex_is_on << '\n';
	std::cout << "\tupload_dir: " << upload_dir << '\n';
	std::cout << "\tmethod: " << method << '\n';
	std::cout << "\tcgi_extension: " << cgi_extension << '\n';
	std::cout << "\tcgi_path: " << cgi_path << '\n';
	std::cout << "\tEND LOCATION: " << path << '\n';
}