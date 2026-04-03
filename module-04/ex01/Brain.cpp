#include <iostream>
#include "./Brain.hpp"

/*Brain ctors/dtor*/
Brain::Brain() : ideas()
{
	std::cout << "Brain default ctor called\n";
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain copy ctor called\n";
	for (std::size_t i = 0; i < 100; ++i)
		this->ideas[i] = other.ideas[i];
}

Brain::~Brain()
{
	std::cout << "Brain dtor called\n";
}


/*Brain operators*/
Brain&	Brain::operator=(const Brain& other)
{
	std::cout << "Brain copy assignment operator called\n";
	if (this != &other)
	{
		for (std::size_t i = 0; i < 100; ++i)
			this->ideas[i] = other.ideas[i];
	}
	return (*this);
}

/*Brain methods*/
Brain	*Brain::clone(void) const
{
	Brain	*_clone = new Brain();

	for (std::size_t i = 0; i < 100; ++i)
		_clone->ideas[i] = this->ideas[i];

	return (_clone);
}

std::string	Brain::getIdea(int idx) const
{
	if (idx >= 0 && idx < 100)
		return (this->ideas[idx]);
	return ("");
}

void	Brain::setIdea(int idx, const std::string& idea)
{
	if (idx >= 0 && idx < 100)
		this->ideas[idx] = idea;
}
