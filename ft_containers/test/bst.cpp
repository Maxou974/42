#include "map.hpp"
#include "pair.hpp"
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#define SIZE 10

void	shuffle(int *tab)
{
	srand(time(NULL));

	int tmp, a;

	for (int i = 0; i < SIZE; i++)
	{
		a = rand() % SIZE;
		tmp  = tab[i];
		tab[i] = tab[a];
		tab[a] = tmp;
	}
}

using namespace std;

int main()
{
	ft::map< int, string, less<int> > bst;

	int tab[SIZE];

	for (int i = 0; i < SIZE; i++)
		tab[i] = i;

	shuffle(tab);

	for (int i = 0; i < SIZE; i++)
	{
		bst.insert(ft::make_pair(tab[i], "ewfwe"));
	}
	bst.show();

	ft::map< int, string, less<int> >::iterator it;

	it = bst.insert(ft::make_pair(5, "ewfwe")).first;

	cout << (*it).first << "hello\n";
	++it;
	cout << (*it).first << "hello\n";

	cout << (*it).second << "\n";
	(*it).second = "2397";
	cout << (*it).second << "\n";





}