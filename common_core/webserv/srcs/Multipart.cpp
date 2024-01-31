#include "Multipart.hpp"

Multipart::Multipart(const std::string &ContentTypeValue
, std::vector<unsigned char>& request_body)
 : body(request_body)
{
	size_t start_index = ContentTypeValue.find("boundary=");
	if (start_index == std::string::npos)
		boundary = "";
	else
	{
		boundary.assign(ContentTypeValue, start_index + 9);
		boundary.insert(0, "--");
	}
}

Multipart::~Multipart()
{}


bool	Multipart::boundary_match(size_t start)
{
	for (size_t i = 0; i < boundary.size(); i++)
	{
		if (body[i + start] != boundary[i])
			return false;
	}
	return true;
}



void Multipart::set_index_vector()
{	
	for (size_t i = 0; i < body.size(); i++)
	{
		if ( boundary_match(i) )
		{
			size_t s = i + boundary.size() + 1;
			for (size_t j = i + boundary.size() + 1; j < body.size(); j++)
			{
				if ( boundary_match(j) )
				{
					index.push_back(std::make_pair(s, j));
					i = j - 1 ;
					break;
				}
			}
		}
	}
}

// void	Multipart::show_trimed()
// {
// 	for (size_t i = 0; i < index.size(); i++)
// 	{
// 		for (size_t j = index[i].first; j < index[i].second; j++)
// 			std::cout << body[j];
// 		std::cout << "_________________\n";
// 	}

// 	for (size_t i = 0; i < index.size(); i++)
// 	{
// 		std::cout << index[i].first << "|" << index[i].second << '\n';
// 	}
// }

int	Multipart::set_info_vector()
{
	for (size_t i = 0; i < index.size(); i++)
	{
		size_t end_header_index;

		end_header_index = find_string_in_vector(body, index[i].first, "\r\n\r\n");

		if (end_header_index == std::string::npos)
			return 400;

		std::string only_header;
		only_header.assign(body.begin() + index[i].first, body.begin() + end_header_index);
		
		size_t ind;
		if ( (ind = only_header.find("filename=")) == std::string::npos)
			return 400;

		size_t first_dquote = only_header.find('"', ind);
		size_t last_dquote = only_header.find('"', ind + 10);

		if (last_dquote == std::string::npos || first_dquote == std::string::npos)
			return 400;

		struct info inf;
		inf.file_name = std::string(only_header, first_dquote + 1, last_dquote - first_dquote - 1);

		inf.start_data = end_header_index + 4;
		inf.end_data = index[i].second;
		if (inf.file_name != "")
			info_vector.push_back(inf);
	}
	return 200;
}

// void	Multipart::show_info_vector()
// {
// 	for(size_t i = 0; i < info_vector.size(); i++)
// 	{
// 		std::cout << "filename: |" << info_vector[i].file_name << "|\n----------------\n";
		
// 		for (size_t j = info_vector[i].start_data; j < info_vector[i].end_data; j++)
// 				std::cout << body[j];
// 		std::cout << "---------------\n";
// 	}
// }