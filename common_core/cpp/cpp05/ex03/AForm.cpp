#include "AForm.hpp"

AForm::AForm() : _name("Default AForm"), _execute(1), _sign(1), _is_signed(0)
{
	// _is_signed = 0;
}

AForm::AForm(std::string name, int exec, int sign) :_name(name), _execute(exec), _sign(sign), _is_signed(0)
{
	if (_execute > 150 || _sign > 150)
		throw AForm::GradeTooLowException();
	if (_execute < 1 || _sign < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm &ref) : _name(ref._name), _execute(ref._execute), _sign(ref._sign), _is_signed(ref._is_signed)
{}

AForm::~AForm()
{
}

void	AForm::beSigned(Bureaucrat &ref)
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
		throw AForm::GradeTooLowException();
	}
}

int	AForm::getExecute()const{
	return _execute;
}

int	AForm::getSign()const{
	return _sign;
}

std::string AForm::getName()const{
	return _name;
}

bool	AForm::getIsSigned()const{
	return _is_signed;
}

AForm&	AForm::operator=(const AForm &ref)
{
	_is_signed = ref._is_signed;
	return *this;
}

const char * AForm::GradeTooHighException::what() const throw(){
	return "AForm::GradeTooHighException";
}

const char * AForm::GradeTooLowException::what() const throw(){
	return	"AForm::GradeTooLowException";
}

const char * AForm::NotSigned::what() const throw(){
	return "AForm::NotSigned";
}

std::ostream&	operator<<(std::ostream& os, const AForm &r)
{
	os << "AForm: " << r.getName() << " have an exec grade of " << r.getExecute() << " a sign grade of " << r.getSign();
	os << " and ";
	if (r.getIsSigned())
		os << "is signed\n";
	else
		os << "is not signed yet\n";
	return os;
}

void	AForm::check_exec(const Bureaucrat & executor)const
{
	if (!_is_signed)
		throw AForm::NotSigned();
	else if (executor.getGrade() > _execute)
		throw Bureaucrat::GradeTooLowException();
}