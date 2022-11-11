#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern &);
	~Intern
	Form*	makeForm(std::string &, std::string &);
};

#endif