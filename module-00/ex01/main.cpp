#include <iostream>
#include "./PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	std::string	command;

	while (true)
	{
		std::cout << "\nAvailable commands: ADD, SEARCH, EXIT.\n";
		if (!(std::cin >> command) || command == "EXIT")
		{
			std::cout << "Bye!" << std::endl;
			break ;
		}
		else if (command == "ADD")
		{
			std::cin.ignore();
			phonebook.create_contact();
		}
		else if (command == "SEARCH")
			phonebook.search();
	}
	return (0);
}