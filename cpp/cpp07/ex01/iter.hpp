#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>


template<typename T, typename U>
void	iter(T* tab, U size, void (*fct)(T &))
{
	for (U i = 0; i < size; i++)
		fct(tab[i]);
}


template <typename T>
void	add_one(T &a)
{
	a++;
}

template<typename T>
void	print(T &n)
{
	std::cout << n << ' ';
}

#endif