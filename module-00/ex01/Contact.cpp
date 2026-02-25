#include "./Contact.hpp"

Contact::Contact()
{}

Contact::Contact(
	const std::string& fname,
	const std::string& lname,
	const std::string& nickname,
	const std::string& p_number,
	const std::string& d_secret)
{
	this->first_name = fname;
	this->last_name = lname;
	this->nickname = nickname;
	this->phone_number = p_number;
	this->darkest_secret = d_secret;
}

Contact::~Contact()
{}

std::string	Contact::getFirstName(void) const
{
	return (this->first_name);
}

std::string	Contact::getLastName(void) const
{
	return (this->last_name);
}

std::string	Contact::getNickname(void) const
{
	return (this->nickname);
}

std::string	Contact::getPhoneNumber(void) const
{
	return (this->phone_number);
}

std::string	Contact::getDarkestSecret(void) const
{
	return (this->darkest_secret);
}
