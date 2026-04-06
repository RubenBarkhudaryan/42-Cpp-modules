#include "./Bureaucrat.hpp"

/*Bureaucrat ctors/dtor*/
Bureaucrat::Bureaucrat() :
	name("default"),
	grade(150)
{
	std::cout << "Bureaucrat default ctor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) :
	name(name),
	grade(grade)
{
	std::cout << "Bureaucrat parameterized ctor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) :
	name(other.name),
	grade(other.grade)
{
	std::cout << "Bureaucrat copy ctor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat dtor called" << std::endl;
}

/*Bureaucrat operators*/
Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->grade = other.grade;
	}
	return (*this);
}

Bureaucrat&	Bureaucrat::operator++(void)
{
	
}

Bureaucrat	Bureaucrat::operator++(int)
{}

Bureaucrat&	Bureaucrat::operator--(void)
{}

Bureaucrat	Bureaucrat::operator--(int)
{}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".\n";

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