#include <ctime>
#include <cstdlib>
#include <iostream>
#include "./Intern.hpp"
#include "./Bureaucrat.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./PresidentialPardonForm.hpp"

int	main()
{
	std::srand(std::time(0));

	try
	{
		Bureaucrat	bob("Bob", 50);
		Bureaucrat	jim("Jim", 140);

		Intern		someIntern;

		std::cout << bob << std::endl;
		std::cout << jim << std::endl;

		AForm*	shrubbery = someIntern.makeForm("shrubbery creation", "home");
		AForm*	robotomy = someIntern.makeForm("robotomy request", "Bender");
		AForm*	pardon = someIntern.makeForm("presidential pardon", "Marvin");

		std::cout << *shrubbery << std::endl;
		std::cout << *robotomy << std::endl;
		std::cout << *pardon << std::endl;

		jim.signForm(*shrubbery);
		bob.signForm(*shrubbery);
		bob.signForm(*robotomy);
		bob.signForm(*pardon);

		std::cout << *shrubbery << std::endl;
		std::cout << *robotomy << std::endl;
		std::cout << *pardon << std::endl;

		jim.executeForm(*shrubbery);
		bob.executeForm(*shrubbery);
		bob.executeForm(*robotomy);
		bob.executeForm(*pardon);

		delete shrubbery;
		delete robotomy;
		delete pardon;
	}
	catch (std::ios_base::failure& e)
	{
		std::cout << "File error: " << e.what() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Execution Exception: " << e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "Unknown error" << std::endl;
	}

	return (0);
}
