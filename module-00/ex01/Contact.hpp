#ifndef CONTACT_HPP

# define CONTACT_HPP

# include <string>

class	Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;

	public:
		/*-----Contact ctor/dtor-----*/
		Contact();
		Contact(const std::string& fname,
				const std::string& lname,
				const std::string& nickname,
				const std::string& p_number,
				const std::string& d_secret);
		~Contact();

		/*-----Contact methods-----*/
		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getNickname() const;
		std::string	getPhoneNumber() const;
		std::string	getDarkestSecret() const;
};

#endif //CONTACT_HPP