#ifndef AUTO_INDEX_H_
#define AUTO_INDEX_H_

#include <cstring>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <iomanip>
#include <iostream>
#include <ios>
#include <vector>
#include <map>
#include <errno.h>
#include <algorithm>
#include <sstream>
#include "webserv_utility.h"

#define LENGTH 50

int		autoindex(std::vector<unsigned char>& body, const std::string &full_path, const std::string &uri_path);

struct Combo{
	std::string path;
	std::string date;
	off_t		size;

	Combo(){}

	Combo(const Combo &ref)
	{ path = ref.path; date = ref.date; size = ref.size; }

	Combo&	operator=(const Combo &ref)
	{ path = ref.path; date = ref.date; size = ref.size; return *this; }

	~Combo(){}

	bool	operator<(struct Combo &ref)
	{ return path < ref.path; }
};

#endif