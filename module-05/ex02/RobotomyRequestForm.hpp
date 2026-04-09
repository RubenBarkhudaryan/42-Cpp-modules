#ifndef ROBOTOMY_REQUEST_FORM

# define ROBOTOMY_REQUEST_FORM

# include <string>
# include "./AForm.hpp"

class	RobotomyRequestForm : public AForm
{
	private:
		std::string	target;

	public:
		/*RobotomyRequestForm ctors/dtor*/
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		~RobotomyRequestForm(); /*override*/

		/*RobotomyRequestForm operators*/
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& other);

		/*RobotomyRequestForm methods*/
		bool					execute(const Bureaucrat& executor) const; /*override*/
};

#endif //ROBOTOMY_REQUEST_FORM