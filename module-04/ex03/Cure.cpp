#include <iostream>
#include "./Cure.hpp"

/*Cure ctors/dtor*/
Cure::Cure() : AMateria("cure")
{}

Cure::Cure(const Cure& other) : AMateria(other)
{}

Cure::~Cure()
{}

/*Cure operators*/
Cure&	Cure::operator=(const Cure& other)
{
	if (this != &other)
		AMateria::operator=(other);
	return (*this);
}

/*Cure methods*/
AMateria	*Cure::clone() const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals "
				<< target.getName()
				<<"'s wounds *\n";
}
