#include <iostream>
#include "./PhoneBook.hpp"

bool	isValidArg(const std::string& arg, const std::string& type)
{
	std::size_t	start;

	if (arg.empty())
		return (false);
	if (type == "name")
	{
		for (std::size_t i = 0; i < arg.length(); ++i)
		{
			if (!std::isalpha(arg[i]))
				return (false);
		}
		return (true);
	}
	else if (type == "phone")
	{
		start = 0;
		if (arg[0] == '+')
			++start;
		if (start == arg.length())
			return (false);
		for (std::size_t i = start; i < arg.length(); ++i)
		{
			if (!std::isdigit(arg[i]))
				return (false);
		}
		return (true);
	}
	return (true);
}

std::string	insert_arg(const std::string& _arg, const std::string& type)
{
	std::string	arg;

	do
	{
		std::cout << "Enter " << _arg << ": ";
		if (!std::getline(std::cin, arg))
		{
			std::cout << "Interrupted process. Program exited with code: 1." << std::endl;
			std::exit(1);
		}
	}	while (!isValidArg(arg, type));
	return (arg);
}

Contact	create_contact()
{
	std::string	fname;
	std::string	lname;
	std::string	nickname;
	std::string	number;
	std::string	secret;

	fname = insert_arg("first name", "name");
	lname = insert_arg("last name", "name");
	nickname = insert_arg("nickname", "name");
	number = insert_arg("phone number", "phone");
	secret = insert_arg("darkest secret", "secret");

	return (Contact(fname, lname, nickname, number, secret));
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