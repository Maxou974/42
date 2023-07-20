#ifndef MIME_HPP_
#define MIME_HPP_

#include <map>
#include <iostream>
#include <string>

const extern	std::map<std::string, std::string> mimemap;

const std::string	get_type_from_file(const std::string& file);

#endif