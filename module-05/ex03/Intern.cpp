#include <iostream>
#include "./Intern.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./PresidentialPardonForm.hpp"

/*Intern ctors/dtor*/
Intern::Intern()
{}

Intern::Intern(const Intern&)
{}

Intern::~Intern()
{}


/*Intern operators*/
Intern&	Intern::operator=(const Intern&)
{
	return (*this);
}

/*intern private methods*/
AForm	*Intern::createShrubberyForm(const std::string& name) const
{
	return (new ShrubberyCreationForm(name));
}

AForm	*Intern::createRobotomyForm(const std::string& name) const
{
	return (new RobotomyRequestForm(name));
}

AForm	*Intern::createPresidentialForm(const std::string& name) const
{
	return (new PresidentialPardonForm(name));
}


/*Intern methods*/
AForm	*Intern::makeForm(const std::string& form_name, const std::string& target) const
{
	const Pair	forms[3] =
	{
		{"create shrubbery", &Intern::createShrubberyForm},
		{"robotomy request", &Intern::createRobotomyForm},
		{"presidential pardon", &Intern::createPresidentialForm}
	};

	for (int i = 0; i < 3; ++i)
	{
		if (form_name == forms[i].form_name)
		{
			std::cout << "Intern creates " << form_name << std::endl;
			return ((this->*forms[i].creator)(target));
		}
	}

	std::cout << "Intern can't create that unknown form. Form name: " << form_name << std::endl;
	return (NULL);
}
