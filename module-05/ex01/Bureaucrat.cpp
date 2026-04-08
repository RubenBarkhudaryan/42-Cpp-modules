#include "./Form.hpp"
#include "./Bureaucrat.hpp"

/*Bureaucrat ctors/dtor*/
Bureaucrat::Bureaucrat() :
	name("default"),
	grade(75)
{
	// std::cout << "Bureaucrat default ctor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) :
	name(name),
	grade(grade)
{
	// std::cout << "Bureaucrat parameterized ctor called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) :
	name(other.name),
	grade(other.grade)
{
	// std::cout << "Bureaucrat copy ctor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	// std::cout << "Bureaucrat dtor called" << std::endl;
}


/*Bureaucrat operators*/
Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	// std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if (this != &other)
		this->grade = other.grade;
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "\n";

	return (os);
}


/*Bureaucrat methods*/
int	Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

std::string	Bureaucrat::getName(void) const
{
	return (this->name);
}

void	Bureaucrat::incrementGrade(void)
{
	if (this->grade <= 1)
		throw	Bureaucrat::GradeTooHighException();
	else
		--(this->grade);
}

void	Bureaucrat::decrementGrade(void)
{
	if (this->grade >= 150)
		throw	Bureaucrat::GradeTooLowException();
	else
		++(this->grade);
}

void	Bureaucrat::signForm(Form& form) const
{
	try
	{
		if(form.beSigned(*this))
		{
			std::cout << this->name
						<< " signed "
						<< form.getName() << std::endl;
		}
	}
	catch (const std::exception& ex)
	{

		std::cout << this->name
					<< " couldn't sign "
					<< form.getName() << " because "
					<< ex.what() << std::endl;
	}
}

/*Bureaucrat inside classes methods*/
const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat::GradeTooHighException -> grade out of range";
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat::GradeTooLowException -> grade out of range";
}
