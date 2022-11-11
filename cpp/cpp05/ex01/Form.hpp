#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form{
	std::string const _name;
	bool	_is_signed;
	const int _execute;
	const int _sign;
public:
	Form();
	Form(std::string, int exec, int sign);
	~Form();
	Form(const Form &);
	Form& operator=(const Form &);
	std::string getName()const;
	bool getIsSigned()const;
	int	getExecute()const;
	int	getSign()const;
	void	beSigned(Bureaucrat &);
};

class FormException : public std::exception{
	std::string _msg;
public:
	FormException();
	FormException(int, int);
	~FormException() throw();
	const char * what()const throw();
};

std::ostream&	operator<<(std::ostream &os, const Form &);


#endif