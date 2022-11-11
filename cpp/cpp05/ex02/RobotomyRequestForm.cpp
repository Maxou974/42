#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("robotomy", 45, 72)
{
	_target = "target";
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form(target, 45, 72)
{
	_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ref) : Form(ref)
{
	_target = ref._target;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm &ref)
{
	Form::operator=(ref);
	_target = ref._target;
	return *this;
}

void	RobotomyRequestForm::execute(const Bureaucrat & executor)const
{
	check_exec(executor);
	std::cout << "*** LOUD DRILL NOISE ***\n";
	if (rand() % 2)
		std::cout << _target << " has been robotomised\n";
	else
		std::cout << "robotomising failed successfully\n";
}