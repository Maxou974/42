#include "Form.hpp"

Form::Form() : _name("Default Form"), _execute(1), _sign(1), _is_signed(0)
{
	// _is_signed = 0;
}

Form::Form(std::string name, int exec, int sign) :_name(name), _execute(exec), _sign(sign), _is_signed(0)
{
	if (_execute > 150 || _sign > 150)
		throw Form::GradeTooLowException();
	if (_execute < 1 || _sign < 1)
		throw Form::GradeTooHighException();
}

Form::Form(const Form &ref) : _name(ref._name), _execute(ref._execute), _sign(ref._sign), _is_signed(ref._is_signed)
{}

Form::~Form()
{
}

void	Form::beSigned(Bureaucrat &ref)
{
	if (_is_signed)
	{
		std::cout << "already signed\n";
	// 	return ;
	}

	if (ref.getGrade()<= _sign)
		_is_signed = 1;
	else
	{
		throw Form::GradeTooLowException();
	}
}

int	Form::getExecute()const{
	return _execute;
}

int	Form::getSign()const{
	return _sign;
}

std::string Form::getName()const{
	return _name;
}

bool	Form::getIsSigned()const{
	return _is_signed;
}

Form&	Form::operator=(const Form &ref)
{
	_is_signed = ref._is_signed;
	return *this;
}

const char * Form::GradeTooHighException::what() const throw(){
	return "Form::GradeTooHighException";
}

const char * Form::GradeTooLowException::what() const throw(){
	return	"Form::GradeTooLowException";
}
std::ostream&	operator<<(std::ostream& os, const Form &r)
{
	os << "Form: " << r.getName() << " have an exec grade of " << r.getExecute() << " a sign grade of " << r.getSign();
	os << " and ";
	if (r.getIsSigned())
		os << "is signed\n";
	else
		os << "is not signed yet\n";
	return os;
}