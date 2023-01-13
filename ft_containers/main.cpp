#include <vector>
#include <iostream>
#include <memory>
#include <string>
#include <string.h>
#include <cstdlib>
#include <stack>
#include <map>


#include "includes/vector.hpp"
#include "includes/iterator.hpp"
#include "includes/type_traits.hpp"
#include "includes/pair.hpp"
#include "includes/map.hpp"

using namespace std;

void	printascii(string str);
void	type_traits_test();
void	vector_test();
void	pair_test();
void	map_test();
void	stack_test();

int main()
{
	printascii("VECTOR");
	vector_test();

	// To use the type_traits test u need to update the makefile
	// And comment the std=c++98 to compare with std
	// printascii("TYPETRAITS");
	// type_traits_test();
	
	printascii("PAIR");
	pair_test();
	
	printascii("MAP");
	map_test();

	printascii("STACK");
	stack_test();

	return 0;
}