#include <cstdlib>
#include <iostream>
#include "./Bureaucrat.hpp"
#include "./RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
	AForm("RobotomyRequestForm", 72, 45),
	target("default_robotomy")
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
	AForm("RobotomyRequestForm", 72, 45),
	target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
	AForm(other),
	target(other.target)
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

/*RobotomyRequestForm operators*/
RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return (*this);
}

/*RobotomyRequestForm methods*/
bool	RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (!this->getStatus())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getExecuteGrade())
		throw AForm::GradeTooLowException();
	if ((std::rand() % 2) == 0)
	{
		std::cout << "[Some drilling noises...]\n"
					<< this->target
					<< " has been robotomized successfully 50% of the time."
					<< std::endl;
	}
	else
		std::cout << "Robotomy failed" << std::endl;
	return (true);
}
