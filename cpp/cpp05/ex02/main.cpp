#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define MAX_GRADE 5
#define FORM PresidentialPardonForm


int main()
{
	srand(time(NULL));

	try
	{
		Bureaucrat max("max", MAX_GRADE);
		FORM f("targettt");
		std::cout << "execute without sign\n";
		f.execute(max);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n";
	try
	{
		Bureaucrat max("max", MAX_GRADE);
		FORM f("targettt");
		std::cout << "sign\n";
		f.beSigned(max);
		std::cout << "execute\n";
		f.execute(max);
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n";
	try
	{
		Bureaucrat max("max", MAX_GRADE);
		FORM f("targettt");
		std::cout << "sign\n";
		f.beSigned(max);
		std::cout << "executeForm\n";
		max.executeForm(f);
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}