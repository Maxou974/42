#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("Anonymous")
{
	_grade = 150;
}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw(Bureaucrat::GradeTooHighException());
	if (grade > 150)
		throw(Bureaucrat::GradeTooLowException());
	_grade = grade;
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
	if (_grade == 1)
		throw(Bureaucrat::GradeTooHighException());
	_grade--;
}

void	Bureaucrat::decrement()
{
	if (_grade == 150)
		throw(Bureaucrat::GradeTooLowException());
	_grade++;
}

std::ostream&	operator<<(std::ostream &os, const Bureaucrat &ref)
{
	os << ref.getName() << ", bureaucrat grade " << ref.getGrade() << "\n";
	return os;
}

const char * Bureaucrat::GradeTooHighException::what() const throw(){
	return "Bureaucrat::GradeTooHighException";
}

const char * Bureaucrat::GradeTooLowException::what() const throw(){
	return	"Bureaucrat::GradeTooLowException";
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