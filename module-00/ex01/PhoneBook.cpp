#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "./PhoneBook.hpp"

int	stringToInt(const std::string& str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (std::isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

PhoneBook::PhoneBook(void)
{
	this->offset = 0;
	this->count = 0;
}

PhoneBook::~PhoneBook()
{}

std::string	PhoneBook::cropArgument(const std::string& arg, std::size_t len)
{
	if (arg.size() > len)
		return (arg.substr(0, 9) + ".");
	return (arg);
}

void	PhoneBook::search(void)
{
	int			idx;
	std::string	ind;

	if (this->count)
	{
		std::cout << std::setw(10) << "|  Index  " << "|"
					<< std::setw(10) << "First Name" << "|"
					<< std::setw(10) << "Last Name" << "|"
					<< std::setw(10) << "Nickname " << "|" <<std::endl;
		std::cout << std::setw(10) << "|---------|"
					<< std::setw(10) << "----------|"
					<< std::setw(10) << "----------|"
					<< std::setw(10) << "----------|" << std::endl;
		for (int i = 0; i < this->count; ++i)
		{
			std::cout << "|" << std::setw(9) << i << "|";
			std::cout << std::setw(10) << this->cropArgument(this->contacts[i].getFirstName(), 10) << "|";
			std::cout << std::setw(10) << this->cropArgument(this->contacts[i].getLastName(), 10) << "|";
			std::cout << std::setw(10) << this->cropArgument(this->contacts[i].getNickname(), 10) << "|";
			std::cout << std::endl;
		}

		std::cout << "\nInsert index (1...8): ";
		if (!std::getline(std::cin, ind))
		{
			std::cout << "\nSearch process interrupted\n";
			return ;
		}

		idx = stringToInt(ind);

		if (idx < 1 || idx > 8)
			std::cout << "Invalid index : " << idx << std::endl;
		else
		{
			if (idx > this->count)
				std::cout << "Contact with index " << idx << " not found." << std::endl;
			else
			{
				std::cout << "First name: " << this->contacts[idx - 1].getFirstName() << std::endl;
				std::cout << "Last name: " << this->contacts[idx - 1].getLastName() << std::endl;
				std::cout << "Nickname: " << this->contacts[idx - 1].getNickname() << std::endl;
				std::cout << "Phone number: " << this->contacts[idx - 1].getPhoneNumber() << std::endl;
				std::cout << "Darkest secret: " << this->contacts[idx - 1].getDarkestSecret() << std::endl;
			}
		}
	}
	else
		std::cout << "No contacts added to phonebook yet." << std::endl;
}


bool	PhoneBook::isValidName(const std::string &arg)
{
	if (arg.empty())
		return (false);

	for (std::size_t i = 0; i < arg.length(); ++i)
	{
		if (!std::isalpha(arg[i]))
			return (false);
	}
	return (true);
}

bool	PhoneBook::isValidNickname(const std::string &arg)
{
	if (arg.empty())
		return (false);

	if (std::isdigit(arg[0]))
		return (false);

	for (std::size_t i = 0; i < arg.length(); ++i)
	{
		if (!std::isalnum(arg[i]) && arg[i] != '_')
			return (false);
	}
	return (true);
}

bool	PhoneBook::isValidPhoneNumber(const std::string& arg)
{
	std::size_t	start;

	if (arg.empty())
		return (false);

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

bool	PhoneBook::isDuplicate(const std::string& arg, char field)
{
	if (field == 'p')
	{
		for (int i = 0; i < this->count; ++i)
		{
			if (this->contacts[i].getPhoneNumber() == arg)
				return (true);
		}
	}

	else if (field == 'n')
	{
		for (int i = 0; i < this->count; ++i)
		{
			if (this->contacts[i].getNickname() == arg)
				return (true);
		}
	}

	return (false);
}

void	PhoneBook::insert_arg(const std::string& _arg_name, std::string& arg, char type)
{
	if (type == 'n')
	{
		while (true)
		{
			std::cout << "Enter " << _arg_name << ": ";
			if (!std::getline(std::cin, arg))
			{
				std::cout << "Process interrupted." << std::endl;
				std::exit(0);
			}
			if (_arg_name == "nickname")
			{
				if (isValidNickname(arg))
					return ;
			}
			else
			{
				if (isValidName(arg))
					return ;
			}
		}
	}

	else if (type == 'p')
	{
		do
		{
			std::cout << "Enter " << _arg_name << ": ";
			if (!std::getline(std::cin, arg))
			{
				std::cout << "Process interrupted." << std::endl;
				std::exit(0);
			}
		}	while (!isValidPhoneNumber(arg));
	}

	else if (type == 's')
	{
		do
		{
			std::cout << "Enter " << _arg_name << ": ";
			if (!std::getline(std::cin, arg))
			{
				std::cout << "Process interrupted." << std::endl;
				std::exit(0);
			}
		}	while (arg.empty());
	}
}

void	PhoneBook::createContact(void)
{
	std::string	fname;
	std::string	lname;
	std::string	nickname;
	std::string	number;
	std::string	secret;

	this->insert_arg("first name", fname, 'n');
	this->insert_arg("last name", lname, 'n');
	this->insert_arg("nickname", nickname, 'n');
	this->insert_arg("phone number", number, 'p');
	this->insert_arg("darkest secret", secret, 's');

	if (isDuplicate(nickname, 'n'))
	{
		std::cout << "Provided nickname is duplicate." << std::endl;
		return ;
	}

	if (isDuplicate(number, 'p'))
	{
		std::cout << "Provided phone number is duplicate." << std::endl;
		return ;
	}

	this->contacts[this->offset % 8] = Contact(fname, lname, nickname, number, secret);
	this->offset = (this->offset + 1) % 8;
	if (this->count < 8)
		++(this->count);
}
