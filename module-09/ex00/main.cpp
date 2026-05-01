#include <iostream>
#include <stdexcept>
#include "./BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		try
		{
			BitcoinExchange	btc;
			btc.evaluate(trimStr(argv[1]));
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	else
	{
		if (argc > 2)
			std::cerr << "Too many arguments to run program" << std::endl;
		else
			std::cerr << "Too few arguments to run program" << std::endl;
		std::cout << "Hint: use [executable] [argument]" << std::endl;
		return (1);
	}
	return (0);
}