#include "../includes/map.hpp"
#include "../includes/pair.hpp"
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <string.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <cstdlib>
#include <random>


class	test{
	public:
	char *tab;
	int n;

	test(){
		tab = strdup("random");
	}

	~test(){ free(tab); }
	
	test	(const test& ref){
		tab = strdup(ref.tab);
	}

	test(char* y){
		tab = strdup(y);
	}

	test&	operator=(const test& ref)
	{
		if (&ref == this)
			return *this;
		free(tab);
		tab = strdup(ref.tab);
		return *this;
	}

};

#define SIZE 20000

using namespace std;

void	shuffle(int *tab, size_t size)
{

	random_device l;
	int tm;
	for (size_t i = 0; i < size; i++)
	{
		int tmp = (int)l() % size;

		tm = tab[i];
		tab[i] = tab[tmp];
		tab[tmp] = tm;
	}
}


void map_time()
{

	int tab[SIZE];

	for (int i = 0; i < SIZE; i++)
		tab[i] = i + 1;

	shuffle(tab, SIZE);

	test m;
		ft::map<int, test> map;

		for (int i = 0; i < SIZE; i++)
			map.insert(ft::make_pair(tab[i], m));

		const ft::map<int, test> map2(map);
	// for (int i = 0; i < 1; i++)
	// {
		ft::pair<int, test> pair_tab[SIZE];

		for (int i = 0; i < SIZE; i++)
			pair_tab[i] = ft::make_pair(tab[i], m);

	
		ft::map<int, test> map3;
		

		for (int i = 0; i < SIZE*SIZE; i++)
		{
			map2.begin();
		}
		
		// map3.insert(map2.begin(), map2.end());

		// map3.insert(&pair_tab[0], &pair_tab[SIZE]);

		// map.clear();
		// for (ft::map<int, test>::iterator it = map.begin(), it != map.end(); )
	// }
}