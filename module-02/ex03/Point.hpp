#ifndef POINT_HPP

# define POINT_HPP

# include "./Fixed.hpp"

class	Point
{
	private:
		Fixed	x;
		Fixed	y;

	public:
		Point(void);
		Point(const float f1, const float f2);
		Point(const Point& other);
		~Point();

		Point&	operator=(const Point& other);

};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif //POINT_HPP