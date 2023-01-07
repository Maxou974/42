#include "../includes/stack.hpp"
#include <iostream>
#include <stack>
#include <vector>
#include <list>

using namespace std;

template< class T, class Cont >
void	print(ft::stack<T, Cont> st)
{
	cout << "size: " << st.size() << "  empty:" << st.empty() << '\n';
	cout << "-- top of stack\n";
	for (size_t i = st.size();  i > 0; i--)
	{
		cout << st.top() << "\n";
		st.pop();
	}
	cout << "-- bot of stack\n";
}


void	stack_test()
{
	ft::stack<int> st;

	st.push(3);
	st.push(2);
	st.push(4);
	st.push(1);
	print(st);


	ft::stack<int> copy(st);
	print(copy);

	cout << (st == copy) << '\n';
	cout << (st != copy) << '\n';
	cout << (st <= copy) << '\n';
	cout << (st >= copy) << '\n';
	cout << (st < copy) << '\n';
	cout << (st > copy) << '\n';

	copy.push(34);

	cout << (st == copy) << '\n';
	cout << (st != copy) << '\n';
	cout << (st <= copy) << '\n';
	cout << (st >= copy) << '\n';
	cout << (st < copy) << '\n';
	cout << (st > copy) << '\n';
{
	ft::stack<string, vector<string> > str_st;
	ft::stack<string, vector<string> > str_st2;

	str_st.push("wefhoiu");
	str_st.push("wfegou");

	str_st2.push("wefigou");
	str_st2.push("dbjfiq");

	print(str_st);
	print(str_st2);

	cout << (str_st == str_st2) << '\n';
	cout << (str_st != str_st2) << '\n';
	cout << (str_st <= str_st2) << '\n';
	cout << (str_st >= str_st2) << '\n';
	cout << (str_st <  str_st2) << '\n';
	cout << (str_st >  str_st2) << '\n';
}
{
	ft::stack<string, vector<string> > str_st;
	ft::stack<string, vector<string> > str_st2;

	str_st.push("hello");
	str_st.push("bye");

	str_st2.push("hello");
	str_st2.push("byedude");

	print(str_st);
	print(str_st2);

	cout << (str_st == str_st2) << '\n';
	cout << (str_st != str_st2) << '\n';
	cout << (str_st <= str_st2) << '\n';
	cout << (str_st >= str_st2) << '\n';
	cout << (str_st <  str_st2) << '\n';
	cout << (str_st >  str_st2) << '\n';
}

{
	ft::stack<string, list<string> > str_st;
	ft::stack<string, list<string> > str_st2;

	str_st.push("hello");
	str_st.push("bye");

	str_st2.push("hello");
	str_st2.push("byedude");

	print(str_st);
	print(str_st2);

	cout << (str_st == str_st2) << '\n';
	cout << (str_st != str_st2) << '\n';
	cout << (str_st <= str_st2) << '\n';
	cout << (str_st >= str_st2) << '\n';
	cout << (str_st <  str_st2) << '\n';
	cout << (str_st >  str_st2) << '\n';
}

}
