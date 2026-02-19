#include <iostream>
#include "./PhoneBook.hpp"

std::string	insert_arg(const std::string& _arg)
{
	std::string	arg;

	while (arg.empty() || !arg[0])
	{
		std::cin.ignore();
		std::cout << "Enter " << _arg << ": ";
		std::getline(std::cin, arg);
		if (!arg[0])
			std::cout << "no\n";
	}
	return (arg);
}

Contact	create_contact()
{
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;

	first_name = insert_arg("first name");
	last_name = insert_arg("last name");
	nickname = insert_arg("nickname");
	phone_number = insert_arg("phone number");
	darkest_secret = insert_arg("darkest secret");

	return (Contact(first_name, last_name, nickname, phone_number, darkest_secret));
}

int	main(void)
{
	PhoneBook	phonebook;
	std::string	command;

	std::cout << "Available commands: ADD, SEARCH, EXIT.\n";
	while (true)
	{
		std::cin >> command;

		if (command == "EXIT")
			break ;
		else if (command == "ADD")
			phonebook.add(create_contact());
		else if (command == "SEARCH")
			phonebook.search();
	}
	return (0);
}