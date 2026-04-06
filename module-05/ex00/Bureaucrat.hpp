#ifndef BUREAUCRAT_HPP

# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

class	Bureaucrat
{

	private:
		int			grade;
		std::string	name;

	public:

		/*Bureaucrat ctors/dtor*/
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat();

		/*Bureaucrat operators*/
		Bureaucrat&	operator=(const Bureaucrat& other);
		Bureaucrat&	operator++(void);
		Bureaucrat	operator++(int);
		Bureaucrat&	operator--(void);
		Bureaucrat	operator--(int);

		/*Bureaucrat methods*/
		std::string	getName(void) const;
		int			getGrade(void) const;
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj);

#endif //BUREAUCRAT_HPP