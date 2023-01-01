#include "../includes/map.hpp"
#include "../includes/pair.hpp"
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#define SIZE 1000

using namespace std;

static void	header_test(string msg)
{
	cout << "\n__________";
	cout << msg;
	cout << "__________\n\n";
}

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

template<class KEY, class T, class comp>
void	show_map(ft::map<KEY, T, comp>& map)
{
	cout << "__________________\n";
	for (typename ft::map<KEY, T, comp>::iterator it = map.begin(); it != map.end(); it++)
		cout << (*it).first << "|" << (*it).second << "   ";
	cout << "\n";
	cout << "size:" << map.size() << '\n';
}


void	map_test()
{
{
	ft::map< int, string, less<int> > bst;

	int tab[SIZE];

	for (int i = 0; i < SIZE; i++)
		tab[i] = i;

	shuffle(tab);


	header_test("AAAH_INSER_LE_BOUTON_INSER");
	for (int i = 0; i < SIZE; i++)
	{
		bst.insert(ft::make_pair(tab[i], "ewfrwgtgjukyt8we"));
	}

	ft::map< int, string, less<int> >::iterator it = bst.begin();

	show_map(bst);

	cout << bst.size() << '\n';

	ft::pair<ft::map< int, string, less<int> >::iterator, bool> pair;

	//inserting something that already exist in the map
	pair = bst.insert(ft::make_pair(SIZE / 2, "hjtm,tetgfbt"));

	it = pair.first;
	
	cout << pair.second << '\n';
	cout << (*it).first << "\n";

	cout << (*it).second << "\n";
	(*it).second = "erhrtj";
	cout << (*it).second << "\n";

	cout << bst.size() << '\n';

	// //insert something greater than everything in the map
	pair = bst.insert(ft::make_pair(SIZE, "acsderh,"));
	
	it = pair.first;

	cout << pair.second << '\n';
	cout << (*it).first << "\n";

	cout << (*it).second << "\n";
	(*it).second = ",yujwdv";
	cout << (*it).second << "\n";

	cout << bst.size() << '\n';

	// //insert something smaller than everything in the map
	pair = bst.insert(ft::make_pair(-1, "ethbeth"));

	it = pair.first;
	
	cout << pair.second << '\n';
	cout << (*it).first << "\n";

	cout << (*it).second << "\n";
	(*it).second = "ewdfwef";
	cout << (*it).second << "\n";

	cout << bst.size() << '\n';


	header_test("COPY_AND_ASSIGNMENT");
	ft::map< int, string, less<int> > bst_copy(bst);

	show_map(bst_copy);
	show_map(bst);

	bst_copy.insert(ft::make_pair(SIZE + 5, "weqohfowe"));

	bst = bst_copy;

	show_map(bst_copy);
	show_map(bst);
	
	bst.clear();

	for(int i = 0; i < 10; i++)
		bst.insert(ft::make_pair(i, "whueof"));
	
	show_map(bst_copy);
	show_map(bst);

	bst_copy = bst;

	if (bst.begin() == bst_copy.begin())
		cout << "is equal\n";
	else
		cout << "is different\n";
		
	show_map(bst_copy);
	show_map(bst);
}
{
	header_test("CONSTRUCTOR");

	ft::map<int, string, greater<int> > rand;

	for(int i = 0; i < 10; i++)
		rand.insert(ft::make_pair(i, "wefgiu"));

	show_map(rand);

	ft::pair<int, string> tabb[10];

	for (int i = 0; i < 10; i++)
		tabb[i] = ft::make_pair(i, "weouf");

	ft::map<int, string> ran(&tabb[0], &tabb[10]);
	
	show_map(ran);

	ft::map<int, string> ran2(ran);
	ft::map<int, string, greater<int> > rand2(rand);

	cout << "here:" <<(*(ran.begin())).first << '\n';

	show_map(ran);
	show_map(ran2);
	show_map(rand);
	show_map(rand2);

}

{
	header_test("ITERATOR");

	ft::map<int, string> m;

	m.insert(ft::make_pair(1,"wef"));
	m.insert(ft::make_pair(2,"wef"));
	m.insert(ft::make_pair(3,"wef"));
	m.insert(ft::make_pair(4,"wef"));

	ft::map<int, string>::iterator it;
	ft::map<int, string>::const_iterator cit;

	it = m.begin();

	cout << (*it).first << '\n';
	it++;
	(*it).second = "wehof";
	cout << (*it).first << '\n';
	cout << (*it).second << '\n';

	cit = m.begin();

	cout << (*cit).first << '\n';

	if (it == cit)
		cout << "same\n";
	else
		cout << "diff\n";
	if (cit == it)
		cout << "same\n";
	else
		cout << "diff\n";
	if (it != cit)
		cout << "diff\n";
	else
		cout << "same\n";
	if (cit != it)
		cout << "diff\n";
	else
		cout << "same\n";

	cit++;
	cit++;
	cout << (*cit).first << '\n';

	ft::map<int, string> m2;

	it = m2.begin();
	cit = m2.end();

	if (it == cit)
		cout << "same\n";
	else
		cout << "diff\n";
	if (cit == it)
		cout << "same\n";
	else
		cout << "diff\n";
	if (it != cit)
		cout << "diff\n";
	else
		cout << "same\n";
	if (cit != it)
		cout << "diff\n";
	else
		cout << "same\n";

	ft::map<int, string>::reverse_iterator rit = m.rbegin();

	cout << (*rit).first << '\n';
	cout << (*(++rit)).first << '\n';
	cout << (*(rit++)).first << '\n';
	cout << (*(rit)).first << '\n';
{	
	ft::map<int, string>::reverse_iterator rbeg = m.rbegin();
	ft::map<int, string>::reverse_iterator rend = m.rend();

	for(; rbeg != rend; rbeg++)
		cout << (*rbeg).first << " ";
	cout << '\n';
	cout << m.empty() << '\n';

}
{
	ft::map<int, string> m3;
	cout << m3.empty() << '\n';

	ft::map<int, string>::reverse_iterator rbeg = m3.rbegin();
	ft::map<int, string>::reverse_iterator rend = m3.rend();

	for(; rbeg != rend; rbeg++)
		cout << (*rbeg).first << " ";
	cout << '\n';

	ft::map<int, string>::iterator begi = m.begin();
	begi++;
	begi++;
	ft::map<int, string>::reverse_iterator cp(begi);

	cout << (*begi).first << " " << (*cp).first << '\n';

	ft::map<int, string>::iterator b = m.end();
	b--;
	cout << (*b).first << '\n';

	ft::map<int, string>::reverse_iterator c = m.rend();
	c--;
	cout << (*c).first << '\n';
}
	{
		ft::map<int, string>::const_reverse_iterator cp = m.rbegin();

		cout << (*cp).first << " " << (*cp).first << '\n';

		ft::map<int, string>::const_iterator b = m.end();
		b--;
		cout << (*b).first << '\n';

		ft::map<int, string>::const_reverse_iterator c = m.rend();
		c--;
		cout << (*c).first << '\n';
	}
}

{
	header_test("ELEMENT_ACCESS");
	ft::map<int, string> map;

	map[1] = "qwedbo";
	map[2] = "qweovfioc";
	map[2] = "qweooc";

	show_map(map);


	map.at(1) = "qdbiqwd";

	try{
		map.at(10) = "cwqbey";

	}
	catch(const exception &e)
	{
		cout << e.what() << '\n';
	}

	show_map(map);
}

{
	header_test("INSERT SUITE");

	ft::map<int, string> map;
	ft::map<int, string>::iterator it;

	it = map.insert(map.end(), ft::make_pair(1, "wecy"));
	cout << (*it).first << "  " << (*it).second << '\n';
	it = map.insert(map.begin(), ft::make_pair(3, "wecegvwy"));
	cout << (*it).first << "  " << (*it).second << '\n';
	it = map.insert(map.begin(), ft::make_pair(2, "wethcy"));
	cout << (*it).first << "  " << (*it).second << '\n';
	it = map.insert(map.begin(), ft::make_pair(4, "wentuykcy"));
	cout << (*it).first << "  " << (*it).second << '\n';

	show_map(map);

	ft::pair<int, string> ta[5];

	ta[0] = ft::make_pair(3, "wedfuewfhhtrhe");
	ta[2] = ft::make_pair(-1, "wfpethhtrhe");
	ta[1] = ft::make_pair(7, "wedfuewfpethe");
	ta[3] = ft::make_pair(87, "wedfuethhtrhe");

	map.insert(&ta[0], &ta[4]);

	show_map(map);

	header_test("ERASE");

	map.erase(map.begin());
	map.erase(--(map.end()));

	ft::map<int, string>::iterator itt = map.begin();

	itt++;
	itt++;

	map.erase(itt);

	show_map(map);

	//3 isnt in the map 4 is in the map
	cout << map.erase(3) << '\n';
	cout << map.erase(4) << '\n';
	cout << map.erase(1) << '\n';

	show_map(map);

	// map[10] = "cwb";
	// map[11] = "cwergb";
	// map[12] = "cwwvthb";
	// map[13] = "crtyjtuywb";
	// map[14] = "cwbsfdvrwerb";


	ft::map<int, string>::iterator itttt = map.end();

	itttt--;
	map.erase(map.begin(), itttt);

	show_map(map);
	
	map.erase(map.begin(), map.end());
	map.erase(map.begin(), map.end());

	show_map(map);
}


}
