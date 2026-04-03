#include <iostream>
#include "./Ice.hpp"

/*Ice ctors/dtor*/
Ice::Ice() : AMateria("ice")
{}

Ice::Ice(const Ice& other) : AMateria(other)
{}

Ice::~Ice()
{}

/*Ice operators*/
Ice&	Ice::operator=(const Ice& other)
{
	if (this != &other)
		AMateria::operator=(other);
	return (*this);
}

/*Ice methods*/
AMateria	*Ice::clone() const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at "
				<< target.getName()
				<< " *\n";
}
