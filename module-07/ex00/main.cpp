#include <iostream>
#include "./whatever.hpp"

//subject case

int	main(void)
{
	int	a = 2;
	int	b = 3;

	::swap(a, b);

	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);

	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

	return (0);
}

/*
//custom tests
int	main()
{
	int	i1 = 5;
	int	i2 = 6;

	std::cout << "-----Basic test-----" << std::endl;

	std::cout << "Before swap" << std::endl;
	std::cout << "i1 = " << i1 << std::endl;
	std::cout << "i2 = " << i2 << std::endl;

	swap(i1, i2);

	std::cout << std::endl;

	std::cout << "After swap" << std::endl;
	std::cout << "i1 = " << i1 << std::endl;
	std::cout << "i2 = " << i2 << std::endl;

	std::cout << std::endl;

	std::cout << "Max = " << max(i1, i2) << std::endl;
	std::cout << "Min = " << min(i1, i2) << std::endl;

	std::cout << "--------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "-----Max min with literals test-----" << std::endl;

	std::cout << "Max = " << max(1, 2) << std::endl;
	std::cout << "Min = " << min(1, 2) << std::endl;

	std::cout << "Max = " << max(1.5f, -1.5f) << std::endl;
	std::cout << "Min = " << min(1.5f, -1.5f) << std::endl;

	std::cout << "------------------------------------" << std::endl;
	std::cout << std::endl;

	i1 = 5;
	i2 = 5;

	std::cout << "-----Max min equals test-----" << std::endl;

	std::cout << "Max = " << max(i1, -i2) << std::endl;
	std::cout << "Min = " << min(i1, i2) << std::endl;

	std::cout << "-----------------------------" << std::endl;
	std::cout << std::endl;

	return (0);
}
	*/