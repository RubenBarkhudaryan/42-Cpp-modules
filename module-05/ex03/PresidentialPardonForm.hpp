#ifndef PRESIDENTIAL_PARDON_FORM

# define PRESIDENTIAL_PARDON_FORM

# include <string>
# include "./AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string	target;

	public:
		/*PresidentialPardonForm ctors/dtor*/
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		~PresidentialPardonForm();

		/*PresidentialPardonForm operators*/
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& other);

		/*PresidentialPardonForm methods*/
		bool					execute(const Bureaucrat& executor) const; /*override*/
};


#endif //PRESIDENTIAL_PARDON_FORM