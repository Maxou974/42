#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template<typename T>
class  MutantStack: public std::stack<T>
{
	typename std::stack<T>::iterator iterator;
	
};


#endif