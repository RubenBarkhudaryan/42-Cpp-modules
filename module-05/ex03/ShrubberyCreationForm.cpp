#include <fstream>
#include "./Bureaucrat.hpp"
#include "./ShrubberyCreationForm.hpp"

static const std::string Tree =
"               ,@@@@@@@,\n\
       ,,,.   ,@@@@@@/@@,  .oo8888o.\n\
    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n\
   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n\
   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n\
   %&&%/ %&%%&&@@\\ V /@@' `88\\8+/88'\n\
   `&%\\ ` /%&'    |.|        \\ '|8'\n\
       |o|        | |         | |\n\
       |.|        | |         | |\n\
jgs \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n";

ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm("ShrubberyCreationForm", 145, 137),
	target("default_shrubbery")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :
	AForm("ShrubberyCreationForm", 145, 137),
	target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
	AForm(other),
	target(other.target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

/*ShrubberyCreationForm operators*/
ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return (*this);
}

/*ShrubberyCreationForm methods*/
bool	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (!this->getStatus())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getExecuteGrade())
		throw AForm::GradeTooLowException();

	std::ofstream	os((this->target + "_shrubbery").c_str());

	if (!os.is_open())
		throw std::ios_base::failure("Failed to open the file");
	os << Tree << std::endl;
	return (true);
}
