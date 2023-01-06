#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <string>

class Bureaucrat{
	const std::string _name;
	int _grade;
public:
	Bureaucrat();
	Bureaucrat(std::string, int);
	Bureaucrat(const Bureaucrat &);
	Bureaucrat& operator=(const Bureaucrat &);
	~Bureaucrat();
	
	int	getGrade()const;
	std::string	getName()const;

	void	increment();
	void	decrement();

	class GradeTooHighException : public std::exception{
	char const * what()const throw();
};

	class GradeTooLowException : public std::exception{
	char const * what()const throw();
};

};

std::ostream&	operator<<(std::ostream&, const Bureaucrat &);

#endif