#include <iostream>
#include "./WrongCat.hpp"

/*WrongCat ctors/dtor*/
WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default ctor called\n";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << "WrongCat copy ctor called\n";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat dtor called\n";
}


/*WrongCat operators*/
WrongCat&	WrongCat::operator=(const WrongCat& other)
{
	std::cout << "WrongCat assignment operator called\n";
	if (this != &other)
		WrongAnimal::operator=(other);
	return (*this);
}


/*WrongCat methods*/
void	WrongCat::makeSound(void) const
{
	std::cout << "Wrong cat sounds: meow meow\n";
}
