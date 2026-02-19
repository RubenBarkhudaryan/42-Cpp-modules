#include "./PhoneBook.hpp"

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

void	PhoneBook::add(const Contact& new_contact)
{
	this->contacts[this->offset % 8] = new_contact;
	this->offset = (this->offset + 1) % 8;
	if (this->count < 8)
		++(this->count);
}

void	PhoneBook::search(void)
{
	std::size_t	idx;

	if (this->offset)
	{
		std::cout << "Insert index (1...8): ";
		std::cin >> idx;

		if (idx < 1 || idx > 8)
			std::cout << "Invalid index : " << idx << std::endl;
		else
		{
			if (idx > this->count)
				std::cout << "Contact with index " << idx << " not found." << std::endl;
			else
			{
				std::cout << std::setw(10) << "Index" << "|" 
							<< std::setw(10) << "First Name" << "|"
							<< std::setw(10) << "Last Name" << "|"
							<< std::setw(10) << "Nickname" << std::endl;
				std::cout << std::setw(10) << idx << "|";
				std::cout << std::setw(10) << this->cropArgument(this->contacts[idx].getFirstName(), 10) << "|";
				std::cout << std::setw(10) << this->cropArgument(this->contacts[idx].getLastName(), 10) << "|";
				std::cout << std::setw(10) << this->cropArgument(this->contacts[idx].getNickname(), 10) << "|";
				std::cout << std::endl;
			}
		}
	}
	else
		std::cout << "No contacts added to phonebook yet." << std::endl;
}