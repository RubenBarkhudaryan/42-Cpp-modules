#include <iostream>
#include "./PhoneBook.hpp"

void	trim_string(std::string& str)
{
	std::size_t	start;
	std::size_t	end;

	if (str.size() == 0)
		return ;

	start = 0;
	end = str.size() - 1;

	while (start < str.size())
	{
		if (!std::isspace(str[start]))
			break ;
		++start;
	}
	if (start == str.size())
	{
		str.clear();
		return ;
	}
	while (end > start)
	{
		if (!std::isspace(str[end]))
			break ;
		--end;
	}
	str = str.substr(start, end - start + 1);
}

int	main(void)
{
	PhoneBook	phonebook;
	std::string	command;

	while (true)
	{
		std::cout << "\nAvailable commands: ADD, SEARCH, EXIT.\n";
		if (!std::getline(std::cin, command))
		{
			std::cout << "Bye!" << std::endl;
			break ;
		}
		trim_string(command);
		if (command == "EXIT")
		{
			std::cout << "Bye!" << std::endl;
			break ;
		}
		else if (command == "ADD")
			phonebook.create_contact();
		else if (command == "SEARCH")
			phonebook.search();
	}
	return (0);
}
