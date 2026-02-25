#ifndef PHONEBOOK_HPP

# define PHONEBOOK_HPP

#include <string>
#include "./Contact.hpp"

class	PhoneBook
{
	private:
		int			count;
		std::size_t	offset;
		Contact		contacts[8];

	private:
		std::string	cropArgument(const std::string& arg, std::size_t len);
		bool		isValidName(const std::string &arg);
		bool		isValidNickname(const std::string &arg);
		bool		isValidPhoneNumber(const std::string& arg);
		bool		isDuplicate(const std::string& arg, char field);
		void		insert_arg(const std::string& _arg_name, std::string& arg, char type);
	
	public:
		/*-----PhoneBook ctor/dtor-----*/
		PhoneBook(void);
		~PhoneBook();

		/*-----PhoneBook methods-----*/
		void	createContact(void);
		void	search(void);
};

#endif //PHONEBOOK_HPP