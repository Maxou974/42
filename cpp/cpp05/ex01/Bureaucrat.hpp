#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <string>

class Form;

class Bureaucrat{
	const std::string _name;
	int _grade;
public:
	Bureaucrat();
	Bureaucrat(std::string, int);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &);
	Bureaucrat& operator=(const Bureaucrat &);
	int	getGrade()const;
	std::string	getName()const;
	void	increment();
	void	decrement();
	void	signForm(Form &);
};

class BureaucratException : public std::exception{
	std::string _msg;
public:
	BureaucratException();
	BureaucratException(int grade);
	~BureaucratException() throw();
	char const * what()const throw();
};

std::ostream&	operator<<(std::ostream&, const Bureaucrat &);

#endif