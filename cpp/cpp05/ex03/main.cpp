#include "Form.hpp"
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
		Form* rrf;

		rrf = someRandomIntern.makeForm("shruberry creationm", "Bender");
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