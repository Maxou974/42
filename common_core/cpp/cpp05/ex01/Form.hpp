#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form{
	std::string const _name;
	const int _execute;
	const int _sign;
	bool	_is_signed;

public:
	Form();
	Form(std::string, int exec, int sign);
	~Form();
	Form(const Form &);
	Form& operator=(const Form &);

	class GradeTooHighException : public std::exception{
	char const * what()const throw();
};

	class GradeTooLowException : public std::exception{
	char const * what()const throw();
};

	std::string getName()const;
	bool getIsSigned()const;
	int	getExecute()const;
	int	getSign()const;
	void	beSigned(Bureaucrat &);
};


std::ostream&	operator<<(std::ostream &os, const Form &);


#endif