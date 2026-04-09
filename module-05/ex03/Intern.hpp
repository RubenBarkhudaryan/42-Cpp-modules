#ifndef INTERN_HPP

# define INTERN_HPP

# include <string>
# include "./AForm.hpp"

class	Intern
{
	private:
		AForm	*createShrubberyForm(const std::string& name) const;
		AForm	*createRobotomyForm(const std::string& name) const;
		AForm	*createPresidentialForm(const std::string& name) const;

	public:
		/*Intern ctors/dtor*/
		Intern();
		Intern(const Intern&);
		~Intern();

		/*Intern operators*/
		Intern&	operator=(const Intern&);

		/*Intern methods*/
		AForm	*makeForm(const std::string& form_name, const std::string& target) const;
};

struct	Pair
{
	std::string	form_name;
	AForm		*(Intern::*creator)(const std::string& name) const;
};

#endif //INTERN_HPP