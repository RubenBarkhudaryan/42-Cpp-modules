#include "./AForm.hpp"

/*AForm ctors/dtor*/
AForm::AForm() :
	name("default"),
	sign_grade(150),
	execute_grade(150),
	is_signed(false)
{}

AForm::AForm(const std::string& name, int sign_grade, int execute_grade) :
	name(name),
	sign_grade(sign_grade),
	execute_grade(execute_grade),
	is_signed(false)
{
	if (sign_grade < 1 || execute_grade < 1)
		throw AForm::GradeTooHighException();
	if (sign_grade > 150 || execute_grade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other) :
	name(other.name),
	sign_grade(other.sign_grade),
	execute_grade(other.execute_grade),
	is_signed(other.is_signed)
{}

AForm::~AForm()
{}

/*AForm operators*/
AForm&	AForm::operator=(const AForm& other)
{
	if (this != &other)
		this->is_signed = other.is_signed;
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const AForm& obj)
{
	os << obj.getName()
		<< ", signed: " << (obj.getStatus() ? "yes" : "no")
		<< ", sign grade: " << obj.getSignGrade()
		<< ", execute grade: " << obj.getExecuteGrade();

	return (os);
}

/*AForm methods*/
bool	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->sign_grade)
		throw	AForm::GradeTooLowException();
	if (this->is_signed)
	{
		std::cout << "The " << this->name << " is already signed " << std::endl;
		return (false);
	}
	this->is_signed = true;
	return (true);
}

std::string	AForm::getName(void) const
{
	return (this->name);
}

int	AForm::getSignGrade(void) const
{
	return (this->sign_grade);
}

int	AForm::getExecuteGrade(void) const
{
	return (this->execute_grade);
}

bool	AForm::getStatus(void) const
{
	return (this->is_signed);
}

/*AForm inside classes methods*/
const char	*AForm::GradeTooHighException::what() const throw()
{
	return "AForm::GradeTooHighException -> grade out of range";
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return "AForm::GradeTooLowException -> grade out of range";
}

const char	*AForm::FormNotSignedException::what() const throw()
{
	return "AForm::FormNotSignedException -> form not signed";
}
