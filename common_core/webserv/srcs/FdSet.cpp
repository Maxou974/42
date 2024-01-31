#include "FdSet.hpp"

FdSet::FdSet()
{}

FdSet::~FdSet()
{}


void	FdSet::add_fd(int fd)
{
	if (std::find(fd_vector.begin(), fd_vector.end(), fd) == fd_vector.end())
		fd_vector.push_back(fd); 
}

void	FdSet::remove_fd(int fd)
{
	for (std::vector<int>::iterator i = fd_vector.begin(); i != fd_vector.end(); i++)
	{
		if (*i == fd)
		{
			fd_vector.erase(i);
			break;
		}
	}
}

fd_set&	FdSet::build_set()
{
	FD_ZERO(&set);

	size_t i;
	for (i = 0; i < fd_vector.size(); i++)
	{
		FD_SET(fd_vector[i], &set);
	}
	return set;
}

int	FdSet::max_fd()
{
	int max = -1;
	for (size_t i = 0; i < fd_vector.size(); i++)
		if (fd_vector[i] > max)
			max = fd_vector[i];
	return max;
}

fd_set&	FdSet::get_set()
{
	return set;
}

bool	FdSet::is_set(int fd)
{
	return FD_ISSET(fd, &set);
}
