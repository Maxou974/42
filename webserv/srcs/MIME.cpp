#include "MIME.hpp"

static std::map<std::string, std::string> init()
{
	std::map<std::string, std::string> map;

	map[".txt"] = "text/plain";
	map[".css"] = "text/css";
	map[".html"] = "text/html";
	map[".xml"] = "text/xml";
	map[".csv"] = "text/csv";

	map[".gif"] = "image/gif";
	map[".jpeg"] = "image/jpeg";
	map[".png"] = "image/png";

	map["undefined"] = "application/octet-stream";
	// map["undefined"] = "";

	return map;
}

const std::map<std::string, std::string> mimemap = init();

const std::string	get_type_from_file(const std::string& file)
{
	size_t pos = file.find_last_of('.');

	const std::map<std::string, std::string>::iterator it;

	if (pos == std::string::npos)
		return mimemap.find("undefined")->second;

	std::string ext(file.begin() + pos, file.end());

	if (mimemap.count(ext))
		return	mimemap.find(ext)->second;
	return mimemap.find("undefined")->second;
}