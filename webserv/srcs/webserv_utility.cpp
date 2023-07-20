#include "webserv_utility.h"

std::string	get_gmt_time(const char *format, time_t ti)
{
	char	buffer[200];
	
	strftime(buffer, 200, format, gmtime(&ti) );

	return std::string(buffer);
}

std::string	get_string_ip_from_addr(const unsigned long addr)
{
	std::string		ret;

	ret = int_to_string(addr >> 24) + ".";
	ret += int_to_string((addr & 0x00ff0000) >> 16) + ".";
	ret += int_to_string((addr & 0x0000ff00) >> 8) + ".";
	ret += int_to_string((addr & 0x000000ff));

	return ret;
}

std::string	timer()
{
	char buff[100];
	time_t tmp = time(NULL);
	struct tm * pTime = localtime( &tmp );



	strftime(buff, 100, "[%d/%m/%y|%X]", pTime);

	return std::string(buff);
}

size_t		string_to_size_t(const std::string& str)
{
	std::stringstream sstream(str);

	size_t result;
	sstream >> result;
	
	return result;
}


size_t find_string_in_vector(const std::vector<unsigned char>& vec, const std::string& str)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        for (size_t j = 0; i + j < vec.size() && j < str.size(); j++)
        {
            if (vec[i + j] != str[j])
                break;
            else if (j == str.size() - 1)
                return i;
        }
    }
    return std::string::npos;
}

size_t find_string_in_vector(const std::vector<unsigned char>& vec, size_t pos, const std::string& str)
{
    for (size_t i = pos; i < vec.size(); i++)
    {
        for (size_t j = 0; i + j < vec.size() && j < str.size(); j++)
        {
            if (vec[i + j] != str[j])
                break;
            else if (j == str.size() - 1)
                return i;
        }
    }
    return std::string::npos;
}