#include "Form.hpp"

Form::Form() : _name("Default Form"), _execute(1), _sign(1)
{
	_is_signed = 0;
}

Form::Form(std::string name, int exec, int sign) :_name(name), _execute(exec), _sign(sign)
{
	_is_signed = 0;
	if (_execute > 150 || _execute < 1
		|| _sign > 150 || _sign < 1)
	{
		FormException l(_execute, _sign);
		throw (l);
	}
}

Form::Form(const Form &ref) : _name(ref._name), _is_signed(ref._is_signed), _execute(ref._execute), _sign(ref._sign)
{}

Form::~Form()
{
}

void	Form::beSigned(Bureaucrat &ref)
{
	if (ref.getGrade()<= _sign)
		_is_signed = 1;
	else
	{
		FormException l(151, 151);
		throw l;
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

FormException::FormException()
{
	_msg = "Form::IsNotSigned";
}

FormException::FormException(int gr1, int gr2)
{
	if (gr1 > 150 || gr2 > 150)
		_msg = "Form::GradeTooLowException";
	else if (gr1 < 1|| gr2 < 1)
		_msg = "Form::GradeTooHighException";
}

FormException::~FormException() throw()
{}

const char * FormException::what() const throw()
{
	return _msg.c_str();
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

void	Form::check_exec(const Bureaucrat & executor)const
{
	if (!_is_signed)
	{
		FormException l;
		throw l;
	}
	else if (executor.getGrade() > _execute)
	{
		BureaucratException l(151);
		throw l;
	}
}