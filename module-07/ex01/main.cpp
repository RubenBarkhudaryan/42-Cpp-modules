#include <iostream>
#include "./iter.hpp"

template <typename T>
void	print(const T& elem)
{
	std::cout << elem << " ";
}

template <typename T>
void	decrement(T& elem)
{
	--elem;
}

int	main()
{
	int	arr[10];

	for (int i = 0; i < 10; ++i)
		arr[i] = i + 1;

	std::cout << "Print int array" << std::endl;
	iter(arr, 10, print<int>);
	std::cout << std::endl << std::endl;

	std::cout << "Decrement int array" << std::endl;
	iter(arr, 10, decrement<int>);
	iter(arr, 10, print<int>);
	std::cout << std::endl;
}