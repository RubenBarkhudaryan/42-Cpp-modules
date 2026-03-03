#include <cmath>
#include <iostream>
#include "./Fixed.hpp"

const int	Fixed::fractional_bits = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	this->val = 0;
}

Fixed::Fixed(const int val)
{
	std::cout << "Int constructor called\n";
	this->val = val << this->fractional_bits;
}

Fixed::Fixed(const float val)
{
	std::cout << "Float constructor called\n";
	this->val = roundf(val * (1 << this->fractional_bits));
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
	return (this->val);
}

void	Fixed::setRawBits(int const val)
{
	this->val = val;
}

float	Fixed::toFloat(void) const
{
	return ((float) this->val / (1 << this->fractional_bits));
}

int	Fixed::toInt(void) const
{
	return (this->val >> this->fractional_bits);
}

std::ostream&	operator<< (std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return (os);
}
