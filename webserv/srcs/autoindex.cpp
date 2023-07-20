#include "autoindex.h"

static std::string& trim_path(std::string &path)
{
	if (path.size() > LENGTH)
	{
		path.resize(LENGTH);
		path[LENGTH - 1] = '>';
		path[LENGTH - 2] = '.';
		path[LENGTH - 3] = '.';
	}
	return path;
}

int		autoindex(std::vector<unsigned char>& body, const std::string &full_path, const std::string &uri_path)
{
	DIR* dir_stream = opendir(full_path.c_str());

	if (dir_stream == NULL && errno == EACCES)
		return 403;
	if (dir_stream == NULL && errno == ENOENT)
		return 404;
	if (dir_stream == NULL)
	{	
		std::cerr << "autoindex(...) : opendir: " << strerror(errno) << '\n';
		return 500;
	}
	
	struct stat st;
	int ret;
	struct dirent * dp;
	std::string path;
	std::vector<struct Combo> tab_file;
	std::vector<struct Combo> tab_dir;
	struct Combo com;

	while( (dp = readdir(dir_stream)) != NULL )
	{
		path = full_path + dp->d_name;

		ret = stat(path.c_str(), &st);
		if (ret == -1)
		{
			std::cerr << "autoindex(...) : stat: " << path << " | " << strerror(errno);
			return 500;
		}
		path = dp->d_name;
		if (S_ISDIR(st.st_mode))
			path += "/";
		if (path[0] != '.' && S_ISDIR(st.st_mode))
		{
			com.path = path;
			com.date = get_gmt_time("%d-%b-%Y %H:%M", st.st_mtim.tv_sec);
			com.size = st.st_size;
			tab_dir.push_back(com);
		}
		else if (path[0] != '.' && !S_ISDIR(st.st_mode))
		{
			com.path = path;
			com.date = get_gmt_time("%d-%b-%Y %H:%M", st.st_mtim.tv_sec);
			com.size = st.st_size;
			tab_file.push_back(com);
		}
	}
	if (closedir(dir_stream) == -1)
	{
		std::cerr << "autoindex(...) : closedir: " << strerror(errno) << '\n';
		return 500;
	}

	std::sort(tab_dir.begin(), tab_dir.end());
	std::sort(tab_file.begin(), tab_file.end());

	body.clear();

	write_string_to_vector("<html>\n<head><title>Index of ", body);
	write_string_to_vector(uri_path, body);
	write_string_to_vector("</title></head>\n", body);
	write_string_to_vector("<body>\n<h1>Index of ", body);
	write_string_to_vector(uri_path, body);
	write_string_to_vector("</h1><hr><pre>", body);
	write_string_to_vector("<a href=\"../\">../</a>\n", body);

	path = "";

	for (size_t i = 0; i < tab_dir.size(); i++)
	{
		path += "<a href=\"" + tab_dir[i].path + "\">";
		path += trim_path(tab_dir[i].path) + "</a>";
		path.append(LENGTH - tab_dir[i].path.size() + 1, ' ');
		path += tab_dir[i].date;
		path += "                   -\n";
	}
	for (size_t i = 0; i < tab_file.size(); i++)
	{
		path += "<a href=\"" + tab_file[i].path + "\">";
		path += trim_path(tab_file[i].path) + "</a>";
		path.append(LENGTH - tab_file[i].path.size() + 1, ' ');
		path += tab_file[i].date;
		path += "   ";
		std::string si(int_to_string(tab_file[i].size));
		si.insert(0, 17 - si.size(), ' ');
		path += si + '\n';
	}

	write_string_to_vector(path, body);
	write_string_to_vector("</pre><hr></body></html>", body);

	return 200;
}