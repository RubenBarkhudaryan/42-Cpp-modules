#include <iostream>
#include "./RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		RPN	rpn;
		rpn.calculate(argv[1]);
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
