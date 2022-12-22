#include <vector>
#include <iostream>
#include <memory>
#include <string>
#include <string.h>
#include <cstdlib>


#include "includes/vector.hpp"
#include "includes/iterator.hpp"
#include "includes/type_traits.hpp"

using namespace std;

void	printascii(string str);
void	type_traits_test();
void	vector_test();

template<typename T>
void fctt(ft::vector<T>& vect)
{
	for (typename ft::vector<T>::size_type i = 0; i < vect.size(); i++)
		cout << vect[i] << " | ";
	cout << '\n';
	cout << "ft::capacity: " << vect.capacity() << "  ft::size: " << vect.size() << '\n';
}

template<typename T>
void fctt(std::vector<T>& vect)
{
	for (typename std::vector<T>::size_type i = 0; i < vect.size(); i++)
		cout << vect[i] << " | ";
	cout << '\n';
	cout << "std::capacity: " << vect.capacity() << "  std::size: " << vect.size() << '\n';
}

bool eq(int a, int b)
{
	if (!(a < b) && !(b < a))
		return true;
	return false;
}


int main()
{
	printascii("VECTOR");
	vector_test();
	printascii("TYPETRAITS");
	type_traits_test();
}
