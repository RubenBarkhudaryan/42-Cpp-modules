#include "./Point.hpp"

/*-----Point ctor/dtor-----*/

Point::Point(void) : x(0), y(0)
{}
Point::Point(const float f1, const float f2) : x(f1), y(f2)
{}

Point::Point(const Point& other)
{
	this->x = other.x;
	this->y = other.y;
}

Point::~Point()
{}

/*-----Point ctor/dtor-----*/

Point&	Point::operator=(const Point& other)
{
	if (this != &other)
	{
		this->x = other.x;
		this->y = other.y;
	}
	return (*this);
}
