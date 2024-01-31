#include <vector>
#include <iostream>
#include "MutantStack.hpp"

int main()
{
	MutantStack<int> v;

	v.push(1);
	v.push(3);
	v.push(23);
	v.push(33);
	v.push(334);
	v.push(235);
	v.push(56);
	v.push(6798);

	MutantStack<int>::iterator it = v.begin();

	while (it != v.end())
		std::cout << *it++ << " ";
	std::cout << '\n';

	const MutantStack<int> c_v(v);
	MutantStack<int>::const_iterator c_it;

	c_it = c_v.begin();

	while (c_it != c_v.end())
		std::cout << *c_it++ << " ";
	std::cout << '\n';


	MutantStack<int>::reverse_iterator r_it = v.rbegin();

	while (r_it != v.rend())
		std::cout << *r_it++ << " ";
	std::cout << '\n';

	MutantStack<int> v2;

	v2 = v;

	MutantStack<int>::const_reverse_iterator cr_it = v2.rbegin();

	while (cr_it != v2.rend())
		std::cout << *cr_it++ << " ";
	std::cout << '\n';


}