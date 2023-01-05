#include "../includes/pair.hpp"
#include <utility>
#include <iostream>

using namespace std;

template<class T1, class T2>
void	show(std::pair<T1, T2> a)
{
	cout << "first: " << a.first << "  second: " << a.second << '\n';
}

void	pair_test()
{
	std::pair<string, string>	a;
	a.first = "a";
	a.second = "A";
	show(a);
	std::pair<string, string>	b(a);
	show(b);
	std::pair<string, string>	c = a;
	show(c);
	std::pair<string, string>	d;
	d = a;
	show(d);
	std::pair<string, string>	f("wef", "woeufb");
	show(f);

	show(std::make_pair("wfeoifw", "woiefhowefo"));

	std::pair<int, int> e(1, 2);
	std::pair<float, double> g(e);

	show(e);
	show(g);
}