#include "./Bureaucrat.hpp"
#include "./Form.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "===== TEST 1: VALID CREATION =====" << std::endl;
	try
	{
		Bureaucrat	b1("Alice", 42);
		Form		f1("Contract", 50, 25);

		std::cout << b1 << std::endl;
		std::cout << f1 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== TEST 2: INVALID FORM GRADES =====" << std::endl;
	try
	{
		Form	f2("BadHigh", 0, 10);
		std::cout << f2 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Form	f3("BadLow", 10, 151);
		std::cout << f3 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== TEST 3: SUCCESSFUL SIGN =====" << std::endl;
	try
	{
		Bureaucrat	b2("Boss", 10);
		Form		f4("TopSecret", 20, 5);

		std::cout << "Before signing: " << f4 << std::endl;
		b2.signForm(f4);
		std::cout << "After signing:  " << f4 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== TEST 4: FAILED SIGN =====" << std::endl;
	try
	{
		Bureaucrat	b3("Intern", 100);
		Form		f5("ImportantPaper", 50, 25);

		std::cout << "Before signing: " << f5 << std::endl;
		b3.signForm(f5);
		std::cout << "After signing:  " << f5 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== TEST 5: ALREADY SIGNED FORM =====" << std::endl;
	try
	{
		Bureaucrat	b4("Manager", 30);
		Form		f6("VacationRequest", 50, 25);

		b4.signForm(f6);
		b4.signForm(f6);
		std::cout << f6 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== TEST 6: BORDER CASES =====" << std::endl;
	try
	{
		Bureaucrat	b5("Best", 1);
		Bureaucrat	b6("Worst", 150);
		Form		f7("EasyForm", 150, 150);
		Form		f8("HardForm", 1, 1);

		std::cout << b5 << std::endl;
		std::cout << b6 << std::endl;
		std::cout << f7 << std::endl;
		std::cout << f8 << std::endl;

		b6.signForm(f7);
		b5.signForm(f8);

		std::cout << f7 << std::endl;
		std::cout << f8 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return (0);
}