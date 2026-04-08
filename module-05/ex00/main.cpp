#include <iostream>
#include "./Bureaucrat.hpp"

int main()
{
	std::cout << "===== VALID CREATION =====" << std::endl;
	try
	{
		Bureaucrat a("Alice", 75);
		std::cout << a << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n===== INVALID CREATION (too high) =====" << std::endl;
	try
	{
		Bureaucrat b("Bob", 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n===== INVALID CREATION (too low) =====" << std::endl;
	try
	{
		Bureaucrat c("Charlie", 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n===== INCREMENT TEST =====" << std::endl;
	try
	{
		Bureaucrat d("David", 2);
		std::cout << d << std::endl;

		d.incrementGrade(); // should go to 1
		std::cout << "After increment: " << d << std::endl;

		d.incrementGrade(); // should throw
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n===== DECREMENT TEST =====" << std::endl;
	try
	{
		Bureaucrat e("Eve", 149);
		std::cout << e << std::endl;

		e.decrementGrade(); // should go to 150
		std::cout << "After decrement: " << e << std::endl;

		e.decrementGrade(); // should throw
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n===== COPY + ASSIGNMENT =====" << std::endl;
	try
	{
		Bureaucrat f("Frank", 42);
		Bureaucrat g(f); // copy ctor
		std::cout << "Copy: " << g << std::endl;

		Bureaucrat h("Henry", 100);
		h = f; // assignment
		std::cout << "Assigned: " << h << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}