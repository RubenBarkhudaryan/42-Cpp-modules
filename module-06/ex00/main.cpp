#include <cctype>
#include <string>
#include <iostream>
#include "./ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc == 2)
		ScalarConverter::convert(std::string(argv[1]));
	else
	{
		if (argc > 2)
			std::cerr << "Error: too many arguments" << std::endl;
		else
			std::cerr << "Error: too few arguments" << std::endl;
		std::cout << "Usage: [executable] [argument]" << std::endl;
		return (1);
	}
	return (0);
}
