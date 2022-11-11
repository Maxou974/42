#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
	std::string _target;
public:
	ShrubberyCreationForm();
	~ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm &);
	void	execute(const Bureaucrat & executor)const;
};

#endif