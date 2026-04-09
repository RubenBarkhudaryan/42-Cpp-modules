#include <iostream>
#include "./Bureaucrat.hpp"
#include "./PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
	AForm("PresidentialPardonForm", 25, 5),
	target("default_presidential")
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :
	AForm("PresidentialPardonForm", 25, 5),
	target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :
	AForm(other),
	target(other.target)
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

/*PresidentialPardonForm operators*/
PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return (*this);
}

/*PresidentialPardonForm methods*/
bool	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (!this->getStatus())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getExecuteGrade())
		throw AForm::GradeTooLowException();
	std::cout << this->target
				<< " has been pardoned by Zaphod Beeblebrox."
				<< std::endl;
	return (true);
}
