#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat maxime("maxime", 150);
		maxime.decrement();
		std::cout << maxime;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	try
	{
		Bureaucrat maxime("maxime", 1545);
		maxime.decrement();
		std::cout << maxime;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	try
	{
		Bureaucrat maxime("maxime", -1243);
		maxime.decrement();
		std::cout << maxime;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	try
	{
		Bureaucrat maxime("maxime", 1);
		maxime.increment();
		std::cout << maxime;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	
	Bureaucrat maxime("maxime", 140);
	Bureaucrat mathou = maxime;

	std::cout << mathou;

}