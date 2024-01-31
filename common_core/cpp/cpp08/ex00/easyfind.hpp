#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <algorithm>

template<typename T>
typename T::iterator easyfind(T &container, int n)
{
	return std::find(container.begin(), container.end(), n);
}


#endif