#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("Anonymous")
{
	_grade = 150;
}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	_grade = grade;
	if (grade > 150 || grade < 1)
	{
		BureaucratException l(grade);
		throw(l);
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &ref) : _name(ref._name)
{
	_grade = ref._grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &ref)
{
	_grade = ref._grade;
	return *this;
}

int	Bureaucrat::getGrade()const{
	return _grade; 
}

std::string Bureaucrat::getName()const{
	return _name;
}

void	Bureaucrat::increment()
{
	_grade--;
	if (_grade > 150 || _grade < 1)
	{
		BureaucratException l(_grade);
		throw(l);
	}
}

void	Bureaucrat::decrement()
{
	_grade++;
	if (_grade > 150 || _grade < 1)
	{
		BureaucratException l(_grade);
		throw(l);
	}
}

std::ostream&	operator<<(std::ostream &os, const Bureaucrat &ref)
{
	os << ref.getName() << ", bureaucrat grade " << ref.getGrade() << "\n";
	return os;
}

BureaucratException::BureaucratException()
{
	_msg = "Bureaucrat::DefaultException";
}

BureaucratException::BureaucratException(int grade)
{
	if (grade > 150)
		_msg = "Bureaucrat::GradeToLowException";
	else if (grade < 1)
		_msg = "Bureaucrat::GradeToHighException";
}

const char * BureaucratException::what() const throw(){
	return _msg.c_str();
}

BureaucratException::~BureaucratException() throw()
{
}

void	Bureaucrat::signForm(Form &ref)
{
	if (_grade <= ref.getSign() && ref.getIsSigned() == 0)
	{
		ref.beSigned(*this);
		std::cout << getName() << " signed " << ref.getName() << '\n'; 
	}
	else if (ref.getIsSigned() == 1)
		std::cout << getName() << " couldn't sign " << ref.getName() << " because it's already signed\n";
	else
		std::cout << getName() << " couldn't sign " << ref.getName() << " because grade is too low\n";
}

void	Bureaucrat::executeForm(Form const & form)
{
	form.execute(*this);
}