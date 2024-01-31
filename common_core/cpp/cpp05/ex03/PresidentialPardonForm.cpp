#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("robotomy", 5, 25)
{
	_target = "target";
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 5, 25)
{
	_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ref) : AForm(ref)
{
	_target = ref._target;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm &ref)
{
	AForm::operator=(ref);
	_target = ref._target;
	return *this;
}

void	PresidentialPardonForm::execute(const Bureaucrat & executor)const
{
	check_exec(executor);
	std::cout << _target << " was forgiven by Zaphod Beeblebrox\n";
}