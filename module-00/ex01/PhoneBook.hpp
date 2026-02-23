#pragma once
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "./Contact.hpp"

class	PhoneBook
{
	private:
		Contact		contacts[8];
		std::size_t	offset;
		std::size_t	count;

	private:
		std::string	cropArgument(const std::string& arg, std::size_t len);
	
	public:
		/*-----PhoneBook ctor/dtor-----*/
		PhoneBook(void);
		~PhoneBook();

		/*-----PhoneBook methods-----*/
		void		add(const Contact& new_contact);
		void		search(void);
};