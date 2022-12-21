#include "type_traits.hpp"
//#include <type_traits>
#include <iostream>
#include <string>

using namespace std;


void type_traits_test()
{
{
	ft::is_integral<float> t;
	if(ft::is_integral<float>())
		cout << "is integral\n";
	else
		cout << "not\n";

	if (t)
		cout << "is integral\n";
	else
		cout << "not\n";

	if (t())
		cout << "is integral\n";
	else
		cout << "not\n";

	if (t.value)
		cout << "is integral\n";
	else
		cout << "not\n";

	cout << ft::is_integral<float>::type::value << '\n';

	if (ft::is_integral<float>::value)
		cout << "is integral\n";
	else
		cout << "not\n";
}
{
	ft::is_integral<int> t;
	if(ft::is_integral<int>())
		cout << "is integral\n";
	else
		cout << "not\n";

	if (t)
		cout << "is integral\n";
	else
		cout << "not\n";

	if (t())
		cout << "is integral\n";
	else
		cout << "not\n";

	if (t.value)
		cout << "is integral\n";
	else
		cout << "not\n";

	cout << ft::is_integral<int>::type::value << '\n';

	if (ft::is_integral<int>::value)
		cout << "is integral\n";
	else
		cout << "not\n";
}
}