#ifndef __FD_SET__HPP
#define __FD_SET__HPP

#include "Color.hpp"
#include <sys/select.h>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <iostream>

#define _MAX_FD_ std::max(read_set.max_fd(), write_set.max_fd())

class FdSet
{
	fd_set 				set;
	std::vector<int>	fd_vector;

	FdSet(const FdSet &);
	FdSet& operator=(const FdSet &);

public:
	FdSet();
	~FdSet();

	void	add_fd(int);
	void	remove_fd(int);

	fd_set&	build_set();
	int		max_fd();

	fd_set&	get_set();
	bool	is_set(int);

};



#endif