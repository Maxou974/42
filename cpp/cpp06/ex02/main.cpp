#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>

Base *generate(void)
{
	switch(rand() % 3)
	{
		case 0:
			std::cout << "A generated\n";
			return new A;
		case 1:
			std::cout << "B generated\n";
			return new B;
		case 2:
			std::cout << "C generated\n";
			return new C;
		default:
			return NULL;
	}
}

void	identify(Base* p)
{
	std::cout << "Pointer ";
	if (dynamic_cast<A*>(p))
		std::cout << "Class: A\n";
	if (dynamic_cast<B*>(p))
		std::cout << "Class: B\n";
	if (dynamic_cast<C*>(p))
		std::cout << "Class: C\n";
}

void	identify(Base& p)
{
	std::cout << "Reference ";
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "Class: A\n";
	}
	catch(const std::exception& e)
	{}// {(void)e;}
	try
	{
		dynamic_cast<B&>(p);
		std::cout << "Class: B\n";
	}
	catch(const std::exception& e)
	{(void)e;}
	try
	{
		dynamic_cast<C&>(p);
		std::cout << "Class: C\n";
	}
	catch(const std::exception& e)
	{(void)e;}
}

int main()
{
	srand(time(NULL));

	for (int i = 0; i < 5; i++)
	{	
		Base *tmp = generate();

		identify(tmp);
		identify(*tmp);
		std::cout << '\n';
		delete tmp;
	}
}