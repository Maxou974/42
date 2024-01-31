#include "easyfind.hpp"

int main()
{
	std::vector<int> v(10);

	std::vector<int>::iterator vi = v.begin();

	for (int i = 1; vi != v.end(); vi++,i++)
		*vi = i;

	vi = v.begin();

	for ( ; vi != v.end(); vi++)
		std::cout << *vi << " ";
	std::cout << std::endl;

	vi = easyfind(v, 5);
	if (vi == v.end())
		std::cout << "not found" <<'\n';
	else
		std::cout << "found "<< *vi << '\n';
	
	vi = easyfind(v, 11);
	if (vi == v.end())
	std::cout << "not found" <<'\n';
	else
		std::cout << "found "<< *vi << '\n';

	std::list<int> l;
	std::list<int>::iterator li;

	l.assign(v.begin(), v.end());

	for (li = l.begin() ; li != l.end(); li++)
		std::cout << *li << " ";
	std::cout << std::endl;

	li = easyfind(l, 5);
	if (li == l.end())
		std::cout << "not found" <<'\n';
	else
		std::cout << "found "<< *li << '\n';
	
	li = easyfind(l, 11);
	if (li == l.end())
	std::cout << "not found" <<'\n';
	else
		std::cout << "found "<< *li << '\n';
}