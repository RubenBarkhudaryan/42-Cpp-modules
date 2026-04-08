#include "./Form.hpp"

/*Form ctors/dtor*/
Form::Form() :
	name("default"),
	sign_grade(150),
	execute_grade(150),
	is_signed(false)
{
	// std::cout << "Form default ctor called" << std::endl;
}

Form::Form(const std::string& name, int sign_grade, int execute_grade) :
	name(name),
	sign_grade(sign_grade),
	execute_grade(execute_grade),
	is_signed(false)
{
	// std::cout << "Form parameterized ctor called" << std::endl;
	if (sign_grade < 1 || execute_grade < 1)
		throw Form::GradeTooHighException();
	if (sign_grade > 150 || execute_grade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& other) :
	name(other.name),
	sign_grade(other.sign_grade),
	execute_grade(other.execute_grade),
	is_signed(other.is_signed)
{
	// std::cout << "Form copy ctor called" << std::endl;
}

Form::~Form()
{
	// std::cout << "Form dtor called" << std::endl;
}

/*Form operators*/
Form&	Form::operator=(const Form& other)
{
	// std::cout << "Form copy assignment operator called" << std::endl;
	if (this != &other)
		this->is_signed = other.is_signed;
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Form& obj)
{
	os << obj.getName()
		<< ", signed: " << (obj.getStatus() ? "yes" : "no")
		<< ", sign grade: " << obj.getSignGrade()
		<< ", execute grade: " << obj.getExecuteGrade();

	return (os);
}

/*Form methods*/
bool	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->sign_grade)
		throw	Form::GradeTooLowException();
	if (this->is_signed)
	{
		std::cout << "The " << this->name << " is already signed " << std::endl;
		return (false);
	}
	this->is_signed = true;
	return (true);
}

std::string	Form::getName(void) const
{
	return (this->name);
}

int	Form::getSignGrade(void) const
{
	return (this->sign_grade);
}

int	Form::getExecuteGrade(void) const
{
	return (this->execute_grade);
}

bool	Form::getStatus(void) const
{
	return (this->is_signed);
}

/*Form inside classes methods*/
const char	*Form::GradeTooHighException::what() const throw()
{
	return "Form::GradeTooHighException -> grade out of range";
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return "Form::GradeTooLowException -> grade out of range";
}