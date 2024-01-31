#ifndef AForm_HPP
#define AForm_HPP

#include "Bureaucrat.hpp"

class AForm{
	std::string const _name;
	const int _execute;
	const int _sign;
	bool	_is_signed;

public:
	AForm();
	AForm(std::string, int exec, int sign);
	virtual ~AForm() = 0;
	AForm(const AForm &);
	AForm& operator=(const AForm &);

	class GradeTooHighException : public std::exception{
	char const * what()const throw();
};

	class GradeTooLowException : public std::exception{
	char const * what()const throw();
};

	class NotSigned : public std::exception{
	char const * what()const throw();
};

	std::string getName()const;
	bool getIsSigned()const;
	int	getExecute()const;
	int	getSign()const;
	void	beSigned(Bureaucrat &);
	virtual void	execute(Bureaucrat const & executor)const = 0;
	void	check_exec(Bureaucrat const & executor)const;
};

std::ostream&	operator<<(std::ostream &os, const AForm &);


#endif