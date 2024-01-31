#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
	std::cout << "TO LOW SIGNFORM:\n";
	try
	{
		Form f = Form("form", 149, 149);
		Bureaucrat max("max", 150);
		max.signForm(f);
		std::cout << f;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << "\nTO LOW BESIGN:\n";
	try
	{
		Form f = Form("form", 149, 149);
		Bureaucrat max("max", 150);
		f.beSigned(max);
		std::cout << f;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
		std::cout << "\nEQUAL SIGNFORM:\n";
	try
	{
		Form f = Form("form", 150, 150);
		Bureaucrat max("max", 150);
		max.signForm(f);
		std::cout << f;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << "\nEQUAL BESIGN:\n";
	try
	{
		Form f = Form("form", 150, 150);
		Bureaucrat max("max", 150);
		f.beSigned(max);
		std::cout << f;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << "\nEQUAL SIGNFORM TWICE:\n";
	try
	{
		Form f = Form("form", 150, 150);
		Bureaucrat max("max", 150);
		max.signForm(f);
		max.signForm(f);
		std::cout << f;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << "\nEQUAL BESIGN TWICE:\n";
	try
	{
		Form f = Form("form", 150, 150);
		Bureaucrat max("max", 150);
		f.beSigned(max);
		f.beSigned(max);
		std::cout << f;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << "\nFORM OUT OF RANGE:\n";
	try
	{
		Form f = Form("form", 150, 151);
		Bureaucrat max("max", 150);
		f.beSigned(max);
		f.beSigned(max);
		std::cout << f;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
		try
	{
		Form f = Form("form", 150, 0);
		Bureaucrat max("max", 150);
		f.beSigned(max);
		f.beSigned(max);
		std::cout << f;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}