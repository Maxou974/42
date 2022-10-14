/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 00:02:09 by mabriel           #+#    #+#             */
/*   Updated: 2022/10/14 05:12:44 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstring>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Wrong argument\n";
		return (1);
	}

	std::ifstream ifs(argv[1]);
	if (!(ifs.is_open()))
	{
		std::cout << "Error opening file\n";
		return (1);
	}

	std::string ofs_name(argv[1]);
	ofs_name += ".replace";
	
	std::ofstream ofs;
	ofs.open(ofs_name.c_str(), std::ofstream::out);
	if (!ofs.is_open())
	{
		std::cout << "Error opening output file\n";
		return (1);
	}
	
	std::string buf;
	size_t	len1 = strlen(argv[2]), len2 = strlen(argv[3]), ret, pos ;
	
	while (!ifs.eof())
	{
		std::getline(ifs, buf);
		pos = 0;
		while ((ret = buf.find(argv[2], pos)) != (size_t)-1)
		{
			buf.insert(ret, argv[3]);
			buf.erase(ret + len2, len1);
			pos = ret + len2;
		}
		ofs << buf << '\n';
	}

	ofs.close();
	ifs.close();
	
	return (0);
}