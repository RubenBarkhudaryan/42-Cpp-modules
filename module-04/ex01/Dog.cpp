#include <iostream>
#include "./Dog.hpp"

/*Dog ctors/dtor*/
Dog::Dog() : Animal("Dog"), brain(new Brain())
{
	std::cout << "Dog default ctor called\n";
}

Dog::Dog(const Dog& other) : Animal(other), brain(other.brain->clone())
{
	std::cout << "Dog copy ctor called\n";
}

Dog::~Dog()
{
	std::cout << "Dog dtor called\n";
	delete this->brain;
}

/*Dog opertors*/
Dog&	Dog::operator=(const Dog& other)
{
	std::cout << "Dog assignment operator called\n";
	if (this != &other)
	{
		Animal::operator=(other);
		Brain	*new_brain = other.brain->clone();

		delete this->brain;
		this->brain = new_brain;
	}
	return (*this);
}

/*Dog methods*/
void	Dog::makeSound(void) const
{
	std::cout << "Dog barks: haf haf\n";
}

std::string	Dog::getIdea(int idx) const
{
	return (this->brain->getIdea(idx));
}

void	Dog::setIdea(int idx, const std::string& idea)
{
	this->brain->setIdea(idx, idea);
}
