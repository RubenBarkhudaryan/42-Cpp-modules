#ifndef FORM_HPP

# define FORM_HPP

# include <string>
# include <iostream>
# include <exception>

# include "./Bureaucrat.hpp"

class	Form
{
	private:
		const std::string	name;
		const int			sign_grade;
		const int			execute_grade;
		bool				is_signed;

	public:
		/*Form ctors/dtor*/
		Form();
		Form(const std::string& name, int sign_grade, int execute_grade);
		Form(const Form& other);
		~Form();

		/*Form operators*/
		Form&	operator=(const Form& other);

		/*Form methods*/
		bool		beSigned(const Bureaucrat& bureaucrat);
		std::string	getName(void) const;
		int			getSignGrade(void) const;
		int			getExecuteGrade(void) const;
		bool		getStatus(void) const;

	class	GradeTooHighException : public std::exception
	{
		public:
			const char	*what() const throw();
	};

	class	GradeTooLowException : public std::exception
	{
		public:
			const char	*what() const throw();
	};

};

std::ostream&	operator<<(std::ostream& os, const Form& obj);

#endif //FORM_HPP