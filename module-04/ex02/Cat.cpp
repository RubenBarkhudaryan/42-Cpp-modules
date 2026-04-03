#include <iostream>
#include "./Cat.hpp"

/*Cat ctors/dtor*/
Cat::Cat() : Animal("Cat"), brain(new Brain())
{
	std::cout << "Cat default ctor called\n";
}

Cat::Cat(const Cat& other) : Animal(other), brain(other.brain->clone())
{
	std::cout << "Cat copy ctor called\n";
}

Cat::~Cat()
{
	std::cout << "Cat dtor called\n";
	delete this->brain;
}

/*Cat opertors*/
Cat&	Cat::operator=(const Cat& other)
{
	std::cout << "Cat assignment operator called\n";
	if (this != &other)
	{
		Animal::operator=(other);
		Brain	*new_brain = other.brain->clone();

		delete this->brain;
		this->brain = new_brain;
	}
	return (*this);
}

/*Cat methods*/
void	Cat::makeSound(void) const
{
	std::cout << "Cat meowing: meow meow\n";
}

std::string	Cat::getIdea(int idx) const
{
	return (this->brain->getIdea(idx));
}

void	Cat::setIdea(int idx, const std::string& idea)
{
	this->brain->setIdea(idx, idea);
}
