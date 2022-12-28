#include "map.hpp"
#include "pair.hpp"
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

void	shuffle(int *tab)
{
	srand(time(NULL));

	int tmp, a;

	for (int i = 0; i < 100000; i++)
	{
		a = rand() % 100000;
		tmp  = tab[i];
		tab[i] = tab[a];
		tab[a] = tmp;
	}
}


int main()
{
	ft::bst< int, std::string, std::less<int> > bst;
	ft::pair<int, std::string> a;
	a.first = 4;
	a.second = "un";
	// ft::pair<int, std::string> b;
	// b = ft::make_pair(2, "deux");
	// bst.insert(a);
	// bst.insert(b);
	// bst.insert(ft::make_pair(3, "3"));
	// bst.insert(ft::make_pair(1, "3"));
	// bst.insert(ft::make_pair(9, "3"));
	// bst.insert(ft::make_pair(6, "3"));
	// bst.insert(ft::make_pair(7, "3"));
	// bst.insert(ft::make_pair(8, "3"));
	// bst.insert(ft::make_pair(5, "3"));
	bst.show();

	int tab[100000];

	for (int i = 0; i < 100000; i++)
		tab[i] = i;

	shuffle(tab);

	for (int i = 0; i < 100000; i++)
		bst.insert(ft::make_pair(tab[i], "ewfwe"));

	bst.show();

	for(int i = 99999; i >= 0; i--)
		bst.erase(tab[i]);

	bst.show();


}