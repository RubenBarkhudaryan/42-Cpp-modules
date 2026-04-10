#ifndef AFORM_HPP

# define AFORM_HPP

# include "./Bureaucrat.hpp"
# include <exception>
# include <iostream>
# include <string>

class AForm
{
	private:
	const std::string name;
	const int sign_grade;
	const int execute_grade;
	bool is_signed;

  public:
	/*AForm ctors/dtor*/
	AForm();
	AForm(const std::string &name, int sign_grade, int execute_grade);
	AForm(const AForm &other);
	virtual ~AForm();

	/*AForm operators*/
	AForm			&operator=(const AForm &other);

	/*AForm methods*/
	std::string		getName(void) const;
	int				getSignGrade(void) const;
	int				getExecuteGrade(void) const;
	bool			getStatus(void) const;
	bool			beSigned(const Bureaucrat &bureaucrat);
	virtual bool	execute(const Bureaucrat &executor) const = 0;

	class	GradeTooHighException : public std::exception
	{
		public:
			const char *what() const throw();
	};

	class	GradeTooLowException : public std::exception
	{
		public:
			const char *what() const throw();
	};

	class	FormNotSignedException : public std::exception
	{
		public:
			const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &os, const AForm &obj);

#endif // AFORM_HPP