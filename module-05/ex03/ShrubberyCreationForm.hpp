#ifndef SHRUBBERY_CREATION_FORM

# define SHRUBBERY_CREATION_FORM

# include <string>
# include "./AForm.hpp"

class	ShrubberyCreationForm : public AForm
{
	private:
		std::string	target;

	public:
		/*ShrubberyCreationForm ctors/dtor*/
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm(); /*override*/

		/*ShrubberyCreationForm operators*/
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other);

		/*ShrubberyCreationForm methods*/
		bool					execute(const Bureaucrat& executor) const; /*override*/
};

#endif //SHRUBBERY_CREATION_FORM