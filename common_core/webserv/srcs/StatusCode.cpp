#include "StatusCode.hpp"


static const std::map<int,std::string>	init_map_status_code()
{
	std::map<int, std::string> map;
	map.insert(std::pair<int, std::string>(200, "200 OK"));
	map.insert(std::pair<int, std::string>(201, "201 Created"));
	map.insert(std::pair<int, std::string>(202, "202 Accepted"));
	map.insert(std::pair<int, std::string>(301, "301 Moved Permanently"));
	map.insert(std::pair<int, std::string>(302, "302 Moved Temporarily"));
	map.insert(std::pair<int, std::string>(400, "400 Bad Request"));
	map.insert(std::pair<int, std::string>(403, "403 Forbidden"));
	map.insert(std::pair<int, std::string>(404, "404 Not Found"));
	map.insert(std::pair<int, std::string>(405, "405 Method Not Allowed"));
	map.insert(std::pair<int, std::string>(408, "408 Request Timeout"));
	map.insert(std::pair<int, std::string>(413, "413 Content Too Large"));
	map.insert(std::pair<int, std::string>(414, "414 URI Too Long"));
	map.insert(std::pair<int, std::string>(500, "500 Internal Server Error"));
	map.insert(std::pair<int, std::string>(501, "501 Not Implemented"));
	map.insert(std::pair<int, std::string>(504, "504 Gateway Timeout"));
	map.insert(std::pair<int, std::string>(505, "505 HTTP Version Not Supported"));

	return map;
}

const std::map<int, std::string> map_status_code = init_map_status_code();