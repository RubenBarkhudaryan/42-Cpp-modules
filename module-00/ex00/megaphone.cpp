#pragma once
#include <iostream>
#include <string>

void	toUpper(std::string& str)
{
	for (std::size_t i = 0; i < str.size(); ++i)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
	}
}

int	main(int argc, char **argv)
{
	std::string	arg;

	if (argc >= 2)
	{
		for (int i = 1; i < argc; i++)
		{
			arg = argv[i];
			toUpper(arg);
			std::cout << arg;
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}