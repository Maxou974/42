#include "Intern.hpp"

Intern::Intern()
{return;}

Intern::~Intern()
{return;}

Intern::Intern(const Intern &ref){(void)ref;}

Intern& Intern::operator=(const Intern &ref){(void)ref;return *this;}

static Form*	shru(std::string &ref)
{
	return new ShrubberyCreationForm(ref);
}

static Form*	robo(std::string &ref)
{
	return new RobotomyRequestForm(ref);
}

static Form*	pre(std::string &ref)
{
	return new PresidentialPardonForm(ref);
}

Form*	Intern::makeForm(std::string name, std::string target)
{
	std::string	formName[] = {	std::string("shruberry creation"),
								std::string("robotomy request"),
								std::string("presidential pardon")};
	Form* (*f[3])(std::string &ref);
	f[0] = &shru;
	f[1] = &robo;
	f[2] = &pre;
	for (int i = 0; i < 3; i++)
	{
		if (name == formName[i])
		{
			std::cout << "Intern creates " << name << "\n";
			return (f[i](target));
		}
	}
	std::cout << "No matching name\n";
	return (NULL);
}