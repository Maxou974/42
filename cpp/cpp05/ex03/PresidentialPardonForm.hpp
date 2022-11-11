#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
	std::string _target;
public:
	PresidentialPardonForm();
	~PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &);
	PresidentialPardonForm& operator=(const PresidentialPardonForm &);
	void	execute(const Bureaucrat & executor)const;
};

#endif