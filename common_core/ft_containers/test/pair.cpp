#include "../includes/pair.hpp"
#include <utility>
#include <iostream>

using namespace std;

template<class T1, class T2>
void	show(ft::pair<T1, T2> a)
{
	cout << "first: " << a.first << "  second: " << a.second << '\n';
}

void	pair_test()
{
	ft::pair<string, string>	a;
	a.first = "a";
	a.second = "A";
	show(a);
	ft::pair<string, string>	b(a);
	show(b);
	ft::pair<string, string>	c = a;
	show(c);
	ft::pair<string, string>	d;
	d = a;
	show(d);
	ft::pair<string, string>	f("wef", "woeufb");
	show(f);

	show(ft::make_pair("wfeoifw", "woiefhowefo"));

	ft::pair<int, int> e(1, 2);
	ft::pair<float, double> g(e);

	show(e);
	show(g);
}