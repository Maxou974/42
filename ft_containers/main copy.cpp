#include <vector>
#include <iostream>
#include <memory>
#include "vector.hpp"
#include "iterator.hpp"
// #include "cont/containers/vector.hpp"
// #include "contt/includes/vector.hpp"

#define NL std::cout << '\n';

template<typename T>
void fct(ft::vector<T>& vect)
{
	using namespace std;
	for (typename std::vector<T>::size_type i = 0; i < vect.size(); i++)
		std::cout << vect[i] << " | ";
	cout << '\n';
	cout << "ft::capacity: " << vect.capacity() << "  ft::size: " << vect.size() << '\n';
}

template<typename T>
void fct(std::vector<T>& vect)
{
	for (typename std::vector<T>::size_type i = 0; i < vect.size(); i++)
		std::cout << vect[i] << " | ";
	std::cout << '\n';
	std::cout << "std::capacity: " << vect.capacity() << "  std::size: " << vect.size() << '\n';
}


int main()
{
	ft::vector<std::string> ve;
	ve.push_back("1");
	ve.push_back("2");
	ve.push_back("3");
	ve.push_back("4");
	ve.push_back("5");
	//std::vector<std::string>::iterator it = ve.begin();
	ft::vector<std::string>::iterator beg = ve.begin();
	ft::vector<std::string>::iterator end = ve.end();

	ft::vector<std::string> vee;

	vee.assign(beg, end);

	fct(ve);
	fct(vee);

// 	ft::vector<std::string> ss(3, "bye");
	// ft::vector<std::string> ve(5, "hello");
// 	std::vector<std::string> vee(5, "hello");
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
