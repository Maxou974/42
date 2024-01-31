#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <string>
#include <fstream>
#include <cstdlib>

class AForm;

class Bureaucrat{
	const std::string _name;
	int _grade;
public:
	Bureaucrat();
	Bureaucrat(std::string, int);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &);
	Bureaucrat& operator=(const Bureaucrat &);

	class GradeTooHighException : public std::exception{
	char const * what()const throw();
};

	class GradeTooLowException : public std::exception{
	char const * what()const throw();
};

	int	getGrade()const;
	std::string	getName()const;
	void	increment();
	void	decrement();
	void	signForm(AForm &);
	void	executeForm(AForm const &form);
};

std::ostream&	operator<<(std::ostream&, const Bureaucrat &);

#endif