#include <iostream>
#include "./Harl.hpp"

void	Harl::debug(void)
{
	std::cout << CYAN << DEBUG << RESET << std::endl;
}

void	Harl::info(void)
{
	std::cout << GREEN << INFO << RESET << std::endl;
}

void	Harl::warning(void)
{
	std::cout << YELLOW << WARNING << RESET << std::endl;
}

void	Harl::error(void)
{
	std::cout << RED << ERROR << RESET << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	void	(Harl::*functions[4])(void) = 
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error,
	};

	for (int i = 0; i < 4; ++i)
	{
		if (levels[i] == level)
		{
			(this->*functions[i])();
			break ;
		}
	}
}
