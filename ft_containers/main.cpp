#include <vector>
#include <iostream>
#include <memory>
#include <string>
#include <string.h>
#include <cstdlib>


#include "vector.hpp"
#include "iterator.hpp"
#include "type_traits.hpp"

using namespace std;

void	printascii(string str);
void	type_traits_test();
void	vector_test();

int main()
{
	printascii("VECTOR");
	vector_test();
	printascii("TYPETRAITS");
	//type_traits_test();
}
