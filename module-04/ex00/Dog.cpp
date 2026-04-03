#include <iostream>
#include "./Dog.hpp"

/*Dog ctors/dtor*/
Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog default ctor called\n";
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog copy ctor called\n";
}

Dog::~Dog()
{
	std::cout << "Dog dtor called\n";
}

/*Dog opertors*/
Dog&	Dog::operator=(const Dog& other)
{
	std::cout << "Dog assignment operator called\n";
	if (this != &other)
		Animal::operator=(other);
	return (*this);
}

/*Dog methods*/
void	Dog::makeSound(void) const
{
	std::cout << "Dog barks: haf haf\n";
}
