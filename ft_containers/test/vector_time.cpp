#include <vector>
#include <iostream>
#include <ostream>
#include <memory>
#include "../includes/vector.hpp"
#include "../includes/iterator.hpp"
#include <string>
#include <string.h>
#include <cstdlib>

using namespace std;

template<typename T>
void fct(std::vector<T>& vect)
{
	for (typename std::vector<T>::size_type i = 0; i < vect.size(); i++)
		cout << vect[i] << " | ";
	cout << '\n';
	cout << "ft::capacity: " << vect.capacity() << "  ft::size: " << vect.size() << '\n';
}

#define SIZE 1000000

int main()
{

	// a.push_back(2);
	// a.push_back(3);
	// a.push_back(4);

	// a.insert(a.begin() + 1, 4);

	// ft::vector<int>::iterator it;
	// for (it = a.begin(); it < a.end(); it++)
	// {
	// 	std::cout << *it << " ";
	// }
	std::cout << " hello" << '\n';
}