#include "Intern.hpp"

Intern::Intern()
{}

Intern::~Intern()
{}

Intern::Intern(const Intern &ref){(void)ref;}

Intern& Intern::operator=(const Intern &ref){(void)ref;return *this;}

static AForm*	shru(std::string &ref)
{
	return new ShrubberyCreationForm(ref);
}

static AForm*	robo(std::string &ref)
{
	return new RobotomyRequestForm(ref);
}

static AForm*	pre(std::string &ref)
{
	return new PresidentialPardonForm(ref);
}

AForm*	Intern::makeForm(std::string name, std::string target)
{
	std::string	formName[] = {	std::string("shrubbery creation"),
								std::string("robotomy request"),
								std::string("presidential pardon")};
	AForm* (*f[3])(std::string &ref);
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
	std::cout << "No matching name for '" << name << "'\n";
	return (NULL);
}