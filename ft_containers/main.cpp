#include <vector>
#include <iostream>
#include <memory>
#include "vector.hpp"
#include "iterator.hpp"
// #include "cont/containers/vector.hpp"
// #include "contt/includes/vector.hpp"

#define NL ft::cout << '\n';

template<typename T>
void fct(ft::vector<T>& vect)
{
	using namespace std;
	for (typename ft::vector<T>::size_type i = 0; i < vect.size(); i++)
		cout << vect[i] << " | ";
	cout << '\n';
	cout << "ft::capacity: " << vect.capacity() << "  ft::size: " << vect.size() << '\n';
}

// template<typename T>
// void fct(ft::vector<T>& vect)
// {
// 	using namespace std;
// 	for (typename ft::vector<T>::size_type i = 0; i < vect.size(); i++)
// 		ft::cout << vect[i] << " | ";
// 	cout << '\n';
// 	cout << "ft::capacity: " << vect.capacity() << "  ft::size: " << vect.size() << '\n';
// }


int main()
{
	ft::vector<ft::string> ve;
	ve.push_back("1");
	ve.push_back("2");
	ve.push_back("3");
	ve.push_back("4");
	ve.push_back("5");
//	ft::vector<ft::string>::iterator it = ve.begin() + 1;
	//ft::vector<ft::string>::iterator beg = ve.begin();
	//ft::vector<ft::string>::iterator end = ve.end();
	// ft::vector<ft::string> vee(5);

	ve.insert(ve.begin() + 2, 1, "f");
	ve.clear();

	fct(ve);
	// fct(vee);

// 	ft::vector<ft::string> ss(3, "bye");
	// ft::vector<ft::string> ve(5, "hello");
// 	ft::vector<ft::string> vee(5, "hello");
// NL;
// 	fct(ve);
// 	fct(vee);
// NL;
// 	ve.resize(11, "ello");
// 	vee.resize(11, "ello");
// 	fct(ve);
// 	fct(vee);
// NL;
// 	ve.resize(20);
// 	vee.resize(20);
// 	fct(ve);
// 	fct(vee);
// NL;
// 	ve.reserve(11);
// 	vee.reserve(11);
// 	fct(ve);
// 	fct(vee);

// NL;
// 	vee.pop_back();
// 	ve.pop_back();
// 	vee.pop_back();
// 	ve.pop_back();
// 	fct(vee);
// 	fct(ve);
// NL;

// 	ve.swap(ve);
// 	fct(ve);
// 	fct(ss);

	return 0;
}
