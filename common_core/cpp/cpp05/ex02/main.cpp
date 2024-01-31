#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// #define MAX_GRADE 140
// #define MAX_GRADE 40
#define MAX_GRADE 5
// #define FORM ShrubberyCreationForm
// #define FORM RobotomyRequestForm
#define FORM PresidentialPardonForm


int main()
{
	srand(time(NULL));

	try
	{
		Bureaucrat max("max", MAX_GRADE);
		FORM f("first");
		f.execute(max);
		std::cout << "execute without sign\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n";
	
	try
	{
		std::cout << "fct: execute()\n";
		Bureaucrat max("max", MAX_GRADE);
		FORM f("second");
		f.beSigned(max);
		std::cout << "signed\n";
		f.execute(max);
		std::cout << "executed\n";
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "\n";
	
	try
	{
		std::cout << "fct: executeForm()\n";
		Bureaucrat max("max", MAX_GRADE);
		FORM f("third");
		f.beSigned(max);
		std::cout << "signed\n";
		max.executeForm(f);
		std::cout << "executedForm\n";
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}