#include <iostream>
#include "./Point.hpp"

void	test(const std::string& name,
			Point const& a,
			Point const& b,
			Point const& c,
			Point const& p)
{
	std::cout << name << ": ";
	if (bsp(a, b, c, p))
		std::cout << "INSIDE";
	else
		std::cout << "OUTSIDE";
	std::cout << std::endl;
}

int	main(void)
{
	Point a(0, 0);
	Point b(10, 0);
	Point c(5, 10);

	std::cout << "=== BASIC TESTS ===" << std::endl;

	test("Inside point", a, b, c, Point(5, 5));

	test("Outside point", a, b, c, Point(15, 5));

	test("On edge AB", a, b, c, Point(5, 0));

	test("On vertex A", a, b, c, Point(0, 0));

	test("Near edge outside", a, b, c, Point(5, -1));

	std::cout << "\n=== ORIENTATION TEST ===" << std::endl;

	test("Inside (reversed triangle)", c, b, a, Point(5, 5));

	std::cout << "\n=== SMALL TRIANGLE ===" << std::endl;

	Point d(0, 0);
	Point e(2, 0);
	Point f(1, 2);

	test("Inside small", d, e, f, Point(1, 1));
	test("Outside small", d, e, f, Point(3, 3));

	std::cout << "\n=== NEGATIVE COORDINATES ===" << std::endl;

	Point g(-5, -5);
	Point h(5, -5);
	Point i(0, 5);

	test("Inside negative", g, h, i, Point(0, 0));
	test("Outside negative", g, h, i, Point(-10, 0));

	return (0);
}