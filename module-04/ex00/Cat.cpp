#include <iostream>
#include "./Cat.hpp"

/*Cat ctors/dtor*/
Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat default ctor called\n";
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat copy ctor called\n";
}

Cat::~Cat()
{
	std::cout << "Cat dtor called\n";
}

/*Cat opertors*/
Cat&	Cat::operator=(const Cat& other)
{
	std::cout << "Cat assignment operator called\n";
	if (this != &other)
		Animal::operator=(other);
	return (*this);
}

/*Cat methods*/
void	Cat::makeSound(void) const
{
	std::cout << "Cat meowing: meow meow\n";
}
