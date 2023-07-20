#include "ErrorPages.hpp"

ErrorPages::ErrorPages()
{
	add_error_pages(400, "./www/error/400.html");
	add_error_pages(401, "./www/error/401.html");
	add_error_pages(403, "./www/error/403.html");
	// add_error_pages(404, "./www/error/404.html");
	add_error_pages(410, "./www/error/410.html");
	add_error_pages(500, "./www/error/500.html");
	add_error_pages(502, "./www/error/502.html");
	add_error_pages(503, "./www/error/503.html");
	add_error_pages(504, "./www/error/504.html");
}

ErrorPages::~ErrorPages(){}

ErrorPages::ErrorPages(const ErrorPages &ref)
{ vect = ref.vect; map = ref.map; }

ErrorPages& ErrorPages::operator=(const ErrorPages &ref)
{ vect = ref.vect; map = ref.map; return *this; }

void	ErrorPages::add_error_pages(const int code, const std::string &str)
{
	if ( std::find(vect.begin(), vect.end(), str) == vect.end() )
		vect.push_back(str);
	size_t i;
	for (i = 0; i < vect.size(); i++)
		if (vect[i] == str)
			break;
	map[code] = i;
}

const std::string	ErrorPages::get_path(const int code) const
{
	std::map<int, int>::const_iterator it = map.begin();
	for ( ; it != map.end(); it++)
		if (it->first == code)
			return vect[it->second];
	return "";
}

void	ErrorPages::show() const
{
	std::map<int, int>::const_iterator it = map.begin();

	for ( ; it != map.end(); it++)
	{
		std::cout << it->first << ": " << get_path(it->first) << '\n';
	}	
}

std::string	get_default_error_pages(const int code)
{
	const std::string msg = map_status_code.find(code)->second;
	
	return "<html>\n\
<head>\n\
<title>" + msg + "</title>\n\
</head>\n\
<body>\n\
<center><h1>" + msg + "</h1></center>";
}
