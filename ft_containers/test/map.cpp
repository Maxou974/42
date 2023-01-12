#include "../includes/map.hpp"
#include "../includes/pair.hpp"
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#define SIZE 100

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
		cout << (*it).first << "|" << it->second << "   ";
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
	ft::map< int, string, less<int> > bst_copy2;

	show_map(bst_copy);
	show_map(bst);

	bst_copy.insert(ft::make_pair(SIZE + 5, "weqohfowe"));

	bst_copy2.insert(ft::make_pair(25, "weqowefghfowe"));
	bst_copy2.insert(ft::make_pair(1, "weqowe"));
	bst_copy2.insert(ft::make_pair(-3, "weqowefghwe"));
	bst_copy2.insert(ft::make_pair(12, "we"));

	bst = bst_copy;

	show_map(bst_copy);
	show_map(bst);

	bst = bst_copy2;
	bst_copy2 = bst_copy;

	bst_copy2.insert(ft::make_pair(13, "we"));


	show_map(bst_copy);
	show_map(bst_copy2);
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


	ft::map<int, string>::iterator b = (m.end())--;
	b--;
	cout << (*b).first << '\n';

	ft::map<int, string>::reverse_iterator c = m.rend();
	c--;
	cout << (*c).first << '\n';


	cout << c->first << c->second << '\n';


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
	
{
	header_test("SWAP");
	ft::map<int, string> un;
	ft::map<int, string> deux;

	un.insert(ft::make_pair(1, "wefowe"));
	un.insert(ft::make_pair(2, "weofqfq"));

	deux.insert(ft::make_pair(232, "weofqewffefq"));
	deux.insert(ft::make_pair(2232, "weofqewffefq"));
	deux.insert(ft::make_pair(22332, "weofqegrrberbewffefq"));
	deux.insert(ft::make_pair(23212, "weofwegweggqewegwegwegwegffefq"));

	show_map(un);
	show_map(deux);

	un.swap(deux);

	show_map(un);
	show_map(deux);

}
{
	ft::map<int, string> un;

	un.clear();
	show_map(un);

	un.insert(ft::make_pair(1, "wefowe"));
	show_map(un);
	un.clear();
	show_map(un);

	un.insert(ft::make_pair(1, "wefowe"));
	un.insert(ft::make_pair(2, "wefowe"));
	un.insert(ft::make_pair(-1, "wefowe"));
	show_map(un);
	un.clear();
	show_map(un);


}

{
	header_test("COUNT_AND_FIND");
	ft::map<int, string> un;

	un.insert(ft::make_pair(1, "wefohr3gwrhtykwe"));
	un.insert(ft::make_pair(-2, "wefwegowe"));
	un.insert(ft::make_pair(4, "wefowegthethwe"));
	un.insert(ft::make_pair(0, "wefovghthwe"));
	un.insert(ft::make_pair(-1, "wefowtheherhee"));

	for(int i = -4; i < 5; i++)
		cout << un.count(i) << " ";
	cout << '\n';

	show_map(un);

	ft::map<int, string>::iterator ite;
	ft::map<int, string>::const_iterator c_ite;
	for(int i = -4; i < 5; i++)
	{
		if (un.end() != (ite = un.find(i)))
			cout << (*ite).first << " ";
		else
			cout << "no match ";
		if (un.end() != (c_ite = un.find(i)))
			cout << (*c_ite).first << " ";
		else
			cout << "no match ";
	}
	cout << '\n';

}

{
	header_test("LOWER_BOUND");

	ft::map<int, string> un;

	un.insert(ft::make_pair(1, "wefohr3gwrhtykwe"));
	un.insert(ft::make_pair(-2, "wefwegowe"));
	un.insert(ft::make_pair(4, "wefowegthethwe"));
	un.insert(ft::make_pair(0, "wefovghthwe"));
	un.insert(ft::make_pair(-1, "wefowtheherhee"));

	ft::map<int, string>::iterator ite;
	ft::map<int, string>::const_iterator c_ite;
	for(int i = -4; i <= 5; i++)
	{
		if (un.end() != (ite = un.lower_bound(i)))
			cout << (*ite).first << " ";
		else
			cout << "no match ";
		if (un.end() != (c_ite = un.lower_bound(i)))
			cout << (*c_ite).first << " ";
		else
			cout << "no match ";
	}
	cout << '\n';

	header_test("UPPER_BOUND");

	for(int i = -4; i <= 5; i++)
	{
		if (un.end() != (ite = un.upper_bound(i)))
			cout << (*ite).first << " ";
		else
			cout << "no match ";
		if (un.end() != (c_ite = un.upper_bound(i)))
			cout << (*c_ite).first << " ";
		else
			cout << "no match ";
	}
	cout << '\n';

	header_test("EQUAL_RANGE");
	
	ft::pair<ft::map<int, string>::const_iterator, ft::map<int, string>::const_iterator> c_pa;
	ft::pair<ft::map<int, string>::iterator, ft::map<int, string>::iterator> pa;

	for(int i = -4; i <= 5; i++)
	{
		pa = un.equal_range(i);
		c_pa = un.equal_range(i);

		if (pa.first != un.end())
			cout << (*(pa.first)).first << " ";
		else
			cout << "no match ";
		if (c_pa.first != un.end())
			cout << (*(c_pa.first)).first << " ";
		else
			cout << "no match ";
	}
	cout << '\n';
}
{
	header_test("VALUE_COMPARE");
	ft::map<char,int> mymap;

	mymap['x']=1001;
	mymap['y']=2002;
	mymap['z']=3003;

	cout << "mymap contains:\n";	
	
	ft::pair<char,int> highest = *mymap.rbegin();          // last element	
	ft::map<char,int>::iterator ite = mymap.begin();
	
	do {
		cout << ite->first << " => " << ite->second << '\n';
	} while ( mymap.value_comp()(*ite++, highest) );
}
{
	header_test("KEY_COMPARE");
	ft::map<char,int>::key_compare l;

	cout << l('a','b') << '\n';
}
{
	header_test("COMPARE_OPERATOR");

	ft::map<int, string> ma;
	ft::map<int, string> ma2;

	ma.insert(ft::make_pair(1, "wefiug"));
	ma.insert(ft::make_pair(3, "weiug"));
	ma.insert(ft::make_pair(2, "wefig"));
	ma.insert(ft::make_pair(0, "weiug"));

	ma2.insert(ft::make_pair(1, "wefiug"));
	ma2.insert(ft::make_pair(3, "weiug"));
	ma2.insert(ft::make_pair(2, "wefig"));
	ma.insert(ft::make_pair(0, "weiug"));

	//EQUAL

	cout << "== " << (ma == ma2) << '\n';
	cout << "!= " << (ma != ma2) << '\n';
	cout << "< " << (ma < ma2) << '\n';
	cout << "<= " << (ma <= ma2) << '\n';
	cout << "> " << (ma > ma2) << '\n';
	cout << ">= " << (ma >= ma2) << '\n';
}
{
	ft::map<int, string> ma;
	ft::map<int, string> ma2;

	ma.insert(ft::make_pair(1, "wefiug"));
	ma.insert(ft::make_pair(3, "weiug"));
	ma.insert(ft::make_pair(2, "wefig"));
	ma.insert(ft::make_pair(0, "weiug"));

	ma2.insert(ft::make_pair(1, "wefiug"));
	ma2.insert(ft::make_pair(3, "weiug"));
	ma2.insert(ft::make_pair(2, "wefig"));
	ma2.insert(ft::make_pair(0, "weig"));

	//DIFF on last ma2

	cout << "== " << (ma == ma2) << '\n';
	cout << "!= " << (ma != ma2) << '\n';
	cout << "< " << (ma < ma2) << '\n';
	cout << "<= " << (ma <= ma2) << '\n';
	cout << "> " << (ma > ma2) << '\n';
	cout << ">= " << (ma >= ma2) << '\n';
}
{
	ft::map<int, string> ma;
	ft::map<int, string> ma2;

	ma.insert(ft::make_pair(1, "wefiug"));
	ma.insert(ft::make_pair(3, "weiug"));
	ma.insert(ft::make_pair(2, "wefig"));
	ma.insert(ft::make_pair(0, "weiug"));

	ma2.insert(ft::make_pair(1, "wefiug"));
	ma2.insert(ft::make_pair(3, "weiug"));
	ma2.insert(ft::make_pair(2, "wefig"));
	ma2.insert(ft::make_pair(0, "weiug"));
	ma2.insert(ft::make_pair(4, "weiug"));

	cout << "== " << (ma == ma2) << '\n';
	cout << "!= " << (ma != ma2) << '\n';
	cout << "< " << (ma < ma2) << '\n';
	cout << "<= " << (ma <= ma2) << '\n';
	cout << "> " << (ma > ma2) << '\n';
	cout << ">= " << (ma >= ma2) << '\n';
}
{
	ft::map<int, string> ma;
	ft::map<int, string> ma2;

	ma.insert(ft::make_pair(1, "wefiug"));
	ma.insert(ft::make_pair(3, "weiug"));
	ma.insert(ft::make_pair(2, "wefig"));
	ma.insert(ft::make_pair(0, "weiug"));

	ma2.insert(ft::make_pair(1, "wefiug"));
	ma2.insert(ft::make_pair(3, "weiug"));
	ma2.insert(ft::make_pair(2, "wefig"));

	cout << "== " << (ma == ma2) << '\n';
	cout << "!= " << (ma != ma2) << '\n';
	cout << "< " << (ma < ma2) << '\n';
	cout << "<= " << (ma <= ma2) << '\n';
	cout << "> " << (ma > ma2) << '\n';
	cout << ">= " << (ma >= ma2) << '\n';
}

{
        ft::map<int, string> m;
        ft::map<int, string> ft_m;
        int arr[] = {20, 10, 100, 15, 60, 90, 65, 200, 150}; // size = 9
        for (size_t i = 0; i < 9; ++i)
        {
            m.insert(ft::make_pair(arr[i], "value"));
            ft_m.insert(ft::make_pair(arr[i], "value"));
        }
        ft::map<int, string> const c_m(m.begin(), m.end());
        ft::map<int, string> const c_ft_m(ft_m.begin(), ft_m.end());
        cout << (m.upper_bound(15)->first == ft_m.upper_bound(15)->first);
        cout << (m.upper_bound(65)->first == ft_m.upper_bound(65)->first);
        cout << (m.upper_bound(63)->first == ft_m.upper_bound(63)->first);
        cout << (m.upper_bound(120)->first == ft_m.upper_bound(120)->first);
        cout << (m.upper_bound(70)->first == ft_m.upper_bound(70)->first);
        cout << (m.upper_bound(150)->first == ft_m.upper_bound(150)->first);

        cout << (c_m.upper_bound(15)->first == c_ft_m.upper_bound(15)->first);
        cout << (c_m.upper_bound(65)->first == c_ft_m.upper_bound(65)->first);
        cout << (c_m.upper_bound(63)->first == c_ft_m.upper_bound(63)->first);
        cout << (c_m.upper_bound(120)->first == c_ft_m.upper_bound(120)->first);
        cout << (c_m.upper_bound(70)->first == c_ft_m.upper_bound(70)->first);
        cout << (c_m.upper_bound(150)->first == c_ft_m.upper_bound(150)->first);
}

}


{
	ft::map<int, string> map;

	for (int i = 0; i < 1000; i++)
		map.insert(ft::make_pair(i, "wef"));
	show_map(map);
}


}



// void	map_test()
// {
// 	header_test("HELLO");
// 	ft::map<int, string> map;
// 	ft::map<int, string> map2;
	
// 	show_map(map);

// 	map.insert(ft::make_pair(1, "heelo"));
// 	map.insert(ft::make_pair(2, "heelo"));
// 	map.insert(ft::make_pair(5, "heelo"));
// 	map.insert(ft::make_pair(-1, "heelo"));
// 	map.insert(ft::make_pair(4, "heelo"));
// 	map.insert(ft::make_pair(-3, "heelo"));

// 	show_map(map);
// 	(void)map2;

// 	map2 = map;
// 	show_map(map);
// 	show_map(map2);


// }
