#include <vector>
#include <iostream>
#include <ostream>
#include <memory>
#include "../includes/vector.hpp"
#include <string>
#include <string.h>
#include <cstdlib>

using namespace std;

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
		tab = y;
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

#define SIZE 1000000

void vector_time()
{

	test b(strdup("hello"));

	ft::vector<test> vect(SIZE, b);
	const ft::vector<test> copy(SIZE, b);

	for (int i = 0; i < 4; i++)
	{
		vect.insert(vect.begin(), copy.begin(), copy.end());
		vect.insert(vect.begin(), b);
		vect.insert(vect.begin(), SIZE, b);
	}

	ft::vector<test>::iterator it = vect.begin();

	for (int i = 0; i < 10; i++)
	{
		ft::vector<test> another;
		another.assign(SIZE * 12, b);
		for (it = another.end() - 1; it != another.begin(); it--)
			another.erase(it);
		another.assign(vect.begin(), vect.end());
		another.erase(another.begin(), another.end());
	}



}