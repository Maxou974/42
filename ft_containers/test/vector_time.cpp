#include <vector>
#include <iostream>
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
	std::vector<int> a;

	a.reserve(SIZE+1);
	// for(int i = 0; i < SIZE; i++)
	// 	a.push_back(i);
	
	// //fct(a);
	// cout << "1\n";
	 
	// a.clear();

	int tab[SIZE];

	for(int i = 0; i < SIZE; i++)
		tab[i] = i;
	
	for(int i = 0; i < SIZE; i += 10000)
		a.insert(a.begin(), &tab[i], &tab[i+10000]);
	
	// a.insert(a.begin(), &tab[0], &tab[SIZE]);
	// a.clear();

	// a.assign(&tab[0], &tab[SIZE]);

	cout << "2\n";

	// a.clear();
	// ft::vector<int> b(a.begin(), a.end());

	// swap(a,b);
}