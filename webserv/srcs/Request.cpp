#include "Request.hpp"


Request::Request()
{
    request_is_complete = false;
    header_is_complete = false;

	uri = "";
	method = "";
	query_string = "";
	protocol = "";
}

Request::Request(const Request &ref)
{
    raw_request_vector  = ref.raw_request_vector;
    header_map = ref.header_map;

    uri = ref.uri;
	query_string = ref.query_string;
    method = ref.method;
    protocol = ref.protocol;    
    
    request_is_complete = ref.request_is_complete;
    header_is_complete  = ref.header_is_complete;
}

Request& Request::operator=(const Request &ref)
{
    raw_request_vector  = ref.raw_request_vector;
    header_map = ref.header_map;

    uri = ref.uri;
	query_string = ref.query_string;
    method = ref.method;
    protocol = ref.protocol;    
    
    request_is_complete = ref.request_is_complete;
    header_is_complete  = ref.header_is_complete;
    return *this;
}

Request::~Request()
{}


void    Request::concatenate_request(const char *buffer, size_t buffer_size)
{
    for (size_t i = 0; i < buffer_size; i++)
    {   
        raw_request_vector.push_back(buffer[i]);
    }
}

bool    is_valid_char(int c)
{
    return (isprint(c) || isspace(c)) ;
}

bool    invalid_char_in_vector(const_uchar_vector &vec, size_t pos, size_t n)
{
    for ( size_t i = 0; i < n; i++, pos++)
    {
        if ( is_valid_char(vec[pos]) == false )
            return true;
    }
    return false;
}

size_t  count(const std::string& str, char c)
{
    size_t ret = 0;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] == c)
            ret++;
    }
    return ret;
}

void    Request::parse_request_line(const std::string& request_line)
{
    if (count(request_line, ' ') != 2)
        throw(std::invalid_argument("Bad Request"));
    
    size_t first_space_index = request_line.find_first_of(' ');
    size_t last_space_index = request_line.find_last_of(' ');

    method.assign(request_line, 0, first_space_index);
    uri.assign(request_line, first_space_index + 1, last_space_index - first_space_index - 1);
    protocol.assign(request_line, last_space_index + 1);

	size_t question_index = request_line.find('?', first_space_index + 1);
	if (question_index == std::string::npos)
  		uri.assign(request_line, first_space_index + 1, last_space_index - first_space_index - 1);
	else
	{
		query_string.assign(request_line, question_index + 1, last_space_index - question_index);
		uri.assign(request_line, first_space_index + 1, question_index - first_space_index - 1);
	}

    if (method != "GET" && method != "POST" && method != "DELETE")
        throw(std::invalid_argument("Not Implemented"));

    if (uri.size() > 1024)
        throw(std::invalid_argument("URI Too Long"));

    if (protocol != "HTTP/1.1")
        throw (std::invalid_argument("Not Supported"));
}

void    Request::add_header_in_map(const std::string &str)
{
    size_t index = str.find(": ");

    if (index == std::string::npos)
        throw (std::invalid_argument("Bad Request"));

    std::string key(str, 0, index);
    std::string value(str, index + 2, std::string::npos);

    header_map[key] = value;
}

void    Request::parse_request_header()
{
    size_t  end_header_index = find_string_in_vector(raw_request_vector, "\r\n\r\n");
	
    if ( end_header_index == std::string::npos)
        throw(std::invalid_argument("Bad Request"));

    if ( invalid_char_in_vector(raw_request_vector, 0, end_header_index) )
        throw(std::invalid_argument("Bad Request"));

    const_uchar_vector::const_iterator it = raw_request_vector.begin();

    std::string all_header(it, it + end_header_index);

    std::string request_line(all_header, 0, all_header.find_first_of("\r\n"));

    parse_request_line(request_line);

    all_header.erase(0, all_header.find_first_of("\r\n") + 2);

    size_t n_of_line = count(all_header, '\n');

    for (size_t i = 0; i < n_of_line; i++)
    {
        size_t end_line_carriage = all_header.find_first_of("\r", 0);
        size_t end_line_feed = all_header.find_first_of("\n", 0);

        if (end_line_carriage + 1 != end_line_feed)
            throw (std::invalid_argument("Bad Request"));

        std::string line(all_header, 0, end_line_carriage);

        add_header_in_map(std::string(all_header, 0, end_line_carriage));
        all_header.erase(0, end_line_feed + 1);
    }

    add_header_in_map(all_header); // here all_header have the last header line

    header_is_complete = true;

    if (method == "GET" || method == "DELETE")
    {
        raw_request_vector.clear();
        request_is_complete = true;
    }
	else
	{
    	uchar_vector::iterator itt = raw_request_vector.begin();
    	raw_request_vector.erase(itt , itt + end_header_index + 4);
	}
}

int    Request::parse_request()
{
    if (header_is_complete == false)
    {
        try
        {
            parse_request_header();
			if (header_map.find("Host") == header_map.end())
				return 400;
        }
        catch(std::invalid_argument &e)
        {
            std::cerr << e.what() << '\n';

            if (std::string(e.what()) == "URI Too Long")
                return 414;
            if (std::string(e.what()) == "Not Implemented")
                return 501;
            if (std::string(e.what()) == "Not Supported")
                return 505;
            return 400;
        }
        catch(std::exception &e)
        {
            std::cerr << e.what() << '\n';
            return 500;
        }
    }
	return 200;
}

int    Request::parse_request_body(const size_t max_body_size)
{
	std::string body_size_string = get_header_value_from_key("Content-Length");
	if (method != "POST")
		return 200;

	if (body_size_string == "")
		return 400;

	size_t body_size_int = string_to_size_t(body_size_string);

	if (body_size_int > max_body_size)
		return 413;

	if (raw_request_vector.size() > body_size_int)
		return 400;

	if (raw_request_vector.size() == body_size_int)
		request_is_complete = true;

	return 200;
}


std::string	Request::get_header_value_from_key(const std::string &key) const
{
	std::map<std::string, std::string>::const_iterator it = header_map.find(key);
	
	if (it == header_map.end())
		return "";
	
	return it->second;
}

std::string	Request::get_uri() const
{ return uri; }

std::string	Request::get_query_string() const
{ return query_string; }

std::string Request::get_method() const
{ return method; }

uchar_vector&  Request::get_body()
{ return raw_request_vector; }


std::string Request::get_host() const
{ return get_header_value_from_key("Host"); }