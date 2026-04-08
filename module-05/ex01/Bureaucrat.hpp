#ifndef BUREAUCRAT_HPP

# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>

class	Form;

class	Bureaucrat
{

	private:
		const std::string	name;
		int					grade;

	public:

		/*Bureaucrat ctors/dtor*/
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat();

		/*Bureaucrat operators*/
		Bureaucrat&	operator=(const Bureaucrat& other);
		
		/*Bureaucrat methods*/
		std::string	getName(void) const;
		int			getGrade(void) const;
		void		incrementGrade(void);
		void		decrementGrade(void);
		void		signForm(Form& form) const;

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

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj);

#endif //BUREAUCRAT_HPP