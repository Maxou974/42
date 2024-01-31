#include "chunked-transfer.h"

static std::string	int_to_hexstring(int n)
{
	std::stringstream str;
	str << std::hex << n;
	std::string tmp = str.str();
	std::transform(tmp.begin(), tmp.end(), tmp.begin(), ::toupper);
	
	return tmp;
}

void write_vector_to_vector(const std::vector<unsigned char> &from,  std::vector<unsigned char> &to)
{
	for (size_t i = 0; i < from.size(); i++)
		to.push_back(from[i]);
}

void	chunk_the_vector(std::vector<unsigned char>& msg, size_t chunk_size)
{
	std::vector< std::vector<unsigned char> > msg_tab;
	
	if (msg.size() % chunk_size  == 0)
		msg_tab.resize((msg.size() / chunk_size));
	else
		msg_tab.resize((msg.size() / chunk_size) + 1);

	std::vector< unsigned char >::iterator it;

	size_t i, dist;

	for (i = 0, it = msg.begin(); it != msg.end(); i++)
	{
		dist = std::distance(it, msg.end());
		if (dist > chunk_size)
			dist = chunk_size;
		msg_tab[i].assign(it, it+dist);
		it += dist;
	}

	msg.clear();

	for (i = 0; i < msg_tab.size(); i++)
	{
		write_string_to_vector(int_to_hexstring(msg_tab[i].size()), msg);
		write_string_to_vector("\r\n", msg);
		write_vector_to_vector(msg_tab[i], msg);
		write_string_to_vector("\r\n", msg);
	}
}