#include "iter.hpp"

int main()
{
	int	tab[10] = {1,2,3,4,5,6,7,8,9,10};
	std::string t[5] = {"Hello", "my", "name", "is", "Slim Shady"};

	iter(tab, 10, &print);
	iter(tab, 10, &add_one);
	std::cout << '\n';
	iter(tab, 10, &print);
	std::cout << '\n';
	iter(t, 5, &print);
	std::cout << '\n';
}