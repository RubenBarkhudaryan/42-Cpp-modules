#include <list>
#include <vector>
#include <iostream>

#include "./easyfind.hpp"

int	main()
{
	std::vector<int>	v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	try
	{
		std::cout << *easyfind(v, 2) << std::endl; // OK
		std::cout << *easyfind(v, 10) << std::endl; // throws
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::list<int> l;
	l.push_back(5);
	l.push_back(6);

	try
	{
		std::cout << *easyfind(l, 6) << std::endl;
	}
	catch (...) {}

	return (0);
}