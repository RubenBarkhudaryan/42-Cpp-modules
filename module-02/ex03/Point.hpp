#ifndef POINT_HPP

# define POINT_HPP

# include "./Fixed.hpp"

class	Point
{
	private:
		Fixed	x;
		Fixed	y;

	public:
		/*-----Point ctor/dtor-----*/
		Point(void);
		Point(const float f1, const float f2);
		Point(const Point& other);
		~Point();

		/*-----Point operators-----*/
		Point&	operator=(const Point& other);

		/*-----Point methods-----*/
		Fixed	getX(void) const;
		Fixed	getY(void) const;
		void	setX(Fixed new_x);
		void	setY(Fixed new_y);
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif //POINT_HPP