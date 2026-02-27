#include <iostream>
#include "./Harl.hpp"

void	Harl::debug(void)
{
	std::cout << CYAN;
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << DEBUG << RESET << std::endl;
}

void	Harl::info(void)
{
	std::cout << GREEN;
	std::cout << "[ INFO ]" << std::endl;
	std::cout << INFO << RESET << std::endl;
}

void	Harl::warning(void)
{
	std::cout << YELLOW;
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << WARNING << RESET << std::endl;
}

void	Harl::error(void)
{
	std::cout << RED;
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << ERROR << RESET << std::endl;
}

void	Harl::call(int pos)
{
	void	(Harl::*functions[4])(void) =
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error,
	};

	for (int i = pos; i < 4; ++i)
	{
		(this->*functions[i])();
		std::cout << std::endl;
	}
}

void	Harl::complain(std::string level)
{
	int			idx = -1;
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; ++i)
	{
		if (levels[i] == level)
		{
			idx = i;
			break ;
		}
	}
	this->filter(idx);
}

void	Harl::filter(int level)
{
	switch (level)
	{
		case 0:
			this->call(0);
			break;
		case 1:
			this->call(1);
			break;
		case 2:
			this->call(2);
			break;
		case 3:
			this->call(3);
			break;
		default:
			std::cout << DEFAULT << std::endl;
			break;
	}
}
