#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


int main()
{
	srand(time(NULL));

	try{
		Intern someRandomIntern;
		AForm* rrf;

		rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		Bureaucrat max("max", 1);
		if (rrf)
		{
			rrf->beSigned(max);
			rrf->execute(max);
			delete rrf;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n\n";

	try{
		Intern someRandomIntern;
		AForm* rrf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		Bureaucrat max("max", 1);
		if (rrf)
		{
			rrf->beSigned(max);
			rrf->execute(max);
			delete rrf;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n\n";

	try{
		Intern someRandomIntern;
		AForm* rrf;

		rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
		Bureaucrat max("max", 1);
		if (rrf)
		{
			rrf->beSigned(max);
			rrf->execute(max);
			delete rrf;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	std::cout << "\n\n";

	try{
		Intern someRandomIntern;
		AForm* rrf;

		rrf = someRandomIntern.makeForm("shrubberyation", "Bender");
		Bureaucrat max("max", 1);
		if (rrf)
		{
			rrf->beSigned(max);
			rrf->execute(max);
			delete rrf;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}








}