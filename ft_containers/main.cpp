#include <vector>
#include <iostream>
#include <memory>
#include "vector.hpp"

#define NL std::cout << '\n';

template<typename T>
void fct(ft::vector<T>& vect)
{
	for (typename std::vector<T>::size_type i = 0; i < vect.size(); i++)
		std::cout << vect[i] << " | ";
	std::cout << '\n';
	std::cout << "ft::capacity: " << vect.capacity() << "  ft::size: " << vect.size() << '\n';
}

template<typename T>
void fct(std::vector<T>& vect)
{
	for (typename std::vector<T>::size_type i = 0; i < vect.size(); i++)
		std::cout << vect[i] << " | ";
	std::cout << '\n';
	std::cout << "std::capacity: " << vect.capacity() << "  std::size: " << vect.size() << '\n';
}


int main()
{
	ft::vector<std::string> ss(3, "bye");
	ft::vector<std::string> ve(5, "hello");
	std::vector<std::string> vee(5, "hello");
NL;
	fct(ve);
	fct(vee);
NL;
	ve.resize(11, "ello");
	vee.resize(11, "ello");
	fct(ve);
	fct(vee);
NL;
	ve.resize(20);
	vee.resize(20);
	fct(ve);
	fct(vee);
NL;
	ve.reserve(11);
	vee.reserve(11);
	fct(ve);
	fct(vee);

NL;
	vee.pop_back();
	ve.pop_back();
	vee.pop_back();
	ve.pop_back();
	fct(vee);
	fct(ve);
NL;

	ve.swap(ve);
	fct(ve);
	fct(ss);

	return 0;
}
