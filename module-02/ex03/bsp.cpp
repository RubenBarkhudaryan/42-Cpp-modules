#include "./Point.hpp"

float	cross(Point const a, Point const b, Point const p)
{
	float	ax;
	float	ay;
	float	bx;
	float	by;
	float	px;
	float	py;

	ax = a.getX().toFloat();
	ay = a.getY().toFloat();
	bx = b.getX().toFloat();
	by = b.getY().toFloat();
	px = p.getX().toFloat();
	py = p.getY().toFloat();

	return ((ax - px) * (by - py) - (ay - py) * (bx - px));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float	d1;
	float	d2;
	float	d3;

	d1 = cross(a, b, point);
	d2 = cross(b, c, point);
	d3 = cross(c, a, point);

	if (d1 == 0 || d2 == 0 || d3 == 0)
		return (false);

	return ((d1 > 0 && d2 > 0 && d3 > 0) || (d1 < 0 && d2 < 0 && d3 < 0));
}
