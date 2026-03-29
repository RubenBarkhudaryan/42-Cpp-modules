#include <cmath>
#include <iostream>
#include "./Fixed.hpp"

const int	Fixed::fractional_bits = 8;

/*-----Fixed ctor/dtor-----*/

Fixed::Fixed()
{
	this->val = 0;
}

Fixed::Fixed(const int val)
{
	this->val = val << this->fractional_bits;
}

Fixed::Fixed(const float val)
{
	this->val = roundf(val * (1 << this->fractional_bits));
}

Fixed::Fixed(const Fixed& other)
{
	this->val = other.getRawBits();
}

Fixed::~Fixed()
{}

/*-----Fixed operators-----*/

Fixed&	Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->val = other.getRawBits();

	return (*this);
}

bool	Fixed::operator<(const Fixed& other) const
{
	return (this->val < other.val);
}

bool	Fixed::operator>(const Fixed& other) const
{
	return (this->val > other.val);
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (this->val <= other.val);
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (this->val >= other.val);
}

bool	Fixed::operator==(const Fixed& other) const
{
	return (this->val == other.val);
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (this->val != other.val);
}

Fixed	Fixed::operator+(const Fixed& other)
{
	Fixed	res;

	res.val = this->val + other.val;
	return (res);
}

Fixed	Fixed::operator-(const Fixed& other)
{
	Fixed	res;

	res.val = this->val - other.val;
	return (res);
}

Fixed	Fixed::operator*(const Fixed& other)
{
	Fixed	res;

	res.val = (this->val * other.val) >> fractional_bits;
	return (res);
}

Fixed	Fixed::operator/(const Fixed& other)
{
	Fixed	res;

	res.val = (this->val << fractional_bits) / other.val;
	return (res);
}

Fixed&	Fixed::operator++(void)
{
	++(this->val);
	return (*this);
}

Fixed&	Fixed::operator--(void)
{
	--(this->val);
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);

	++(this->val);
	return (temp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);

	--(this->val);
	return (temp);
}

std::ostream&	operator<< (std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return (os);
}

/*-----Fixed methods-----*/

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
	return (static_cast<float>(this->val) / (1 << this->fractional_bits));
}

int	Fixed::toInt(void) const
{
	return (this->val >> this->fractional_bits);
}

/*-----Fixed static functions-----*/

Fixed&	Fixed::min(Fixed& f1, Fixed& f2)
{
	if (f1 < f2)
		return (f1);
	return (f2);
}

const Fixed&	Fixed::min(const Fixed& f1, const Fixed& f2)
{
	if (f1 < f2)
		return (f1);
	return (f2);
}

Fixed&	Fixed::max(Fixed& f1, Fixed& f2)
{
	if (f1 > f2)
		return (f1);
	return (f2);
}

const Fixed&	Fixed::max(const Fixed& f1, const Fixed& f2)
{
	if (f1 > f2)
		return (f1);
	return (f2);
}
