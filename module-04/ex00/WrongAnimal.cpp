#include <iostream>
#include "WrongAnimal.hpp"

/*WrongAnimal ctors/dtor*/
WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "WrongAnimal default ctor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type)
{
	std::cout << "WrongAnimal copy ctor called\n";
}

WrongAnimal::WrongAnimal(const std::string& type) : type(type)
{
	std::cout << "WrongAnimal parameterized ctor called\n";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal dtor called\n";
}

/*WrongAnimal operators*/
WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
		this->type = other.type;
	return (*this);
}

/*WrongAnimal methods*/
std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "some animal sounds\n";
}
