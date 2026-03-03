#include <iostream>
#include "./Fixed.hpp"

const int	Fixed::fractional_bits = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	this->val = 0;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called\n";
	this->val = other.getRawBits();
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called\n";

	if (this != &other)
		this->val = other.getRawBits();

	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (this->val);
}

void	Fixed::setRawBits(int const val)
{
	this->val = val;
	std::cout << "setRawBits member function called\n";
}
