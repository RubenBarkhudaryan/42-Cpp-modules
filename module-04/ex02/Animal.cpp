#include <iostream>
#include "./Animal.hpp"

/*Animal ctors/dtor*/
Animal::Animal() : type("meta animal")
{
	std::cout << "Animal default ctor called\n";
}

Animal::Animal(const Animal& other) : type(other.type)
{
	std::cout << "Animal copy ctor called\n";
}

Animal::Animal(const std::string& type) : type(type)
{
	std::cout << "Animal parameterized ctor called\n";
}

Animal::~Animal()
{
	std::cout << "Animal dtor called\n";
}

/*Animal operators*/
Animal&	Animal::operator=(const Animal& other)
{
	std::cout << "Animal assignment operator called\n";
	if (this != &other)
		this->type = other.type;
	return (*this);
}

/*Animal methods*/
std::string	Animal::getType(void) const
{
	return (this->type);
}
