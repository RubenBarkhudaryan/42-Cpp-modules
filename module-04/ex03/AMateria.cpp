#include <iostream>
#include "./AMateria.hpp"

/*AMateria ctors/dtor*/
AMateria::AMateria(std::string const &type) : type(type)
{}

AMateria::AMateria(const AMateria& other) : type(other.type)
{}

AMateria::~AMateria()
{}

/*AMateria operators*/
AMateria&	AMateria::operator=(const AMateria& other)
{
	if (this != &other)
		this->type = other.type;
	return (*this);
}

/*AMateria methods*/
std::string const	&AMateria::getType() const
{
	return (this->type);
}

void	AMateria::use(ICharacter &target)
{
	(void)target;
}
