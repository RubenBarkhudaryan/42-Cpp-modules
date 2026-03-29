#include "./Point.hpp"

/*-----Point ctor/dtor-----*/

Point::Point(void) : x(0), y(0)
{}
Point::Point(const float f1, const float f2) : x(f1), y(f2)
{}

Point::Point(const Point &other)
{
	this->x = other.x;
	this->y = other.y;
}

Point::~Point()
{}

/*-----Point operators-----*/

Point &Point::operator=(const Point &other)
{
	if (this != &other)
	{
		this->x = other.x;
		this->y = other.y;
	}
	return (*this);
}

/*-----Point methods-----*/

Fixed Point::getX(void) const
{
	return (this->x);
}

Fixed Point::getY(void) const
{
	return (this->y);
}

void Point::setX(Fixed new_x)
{
	this->x = new_x;
}

void Point::setY(Fixed new_y)
{
	this->y = new_y;
}
