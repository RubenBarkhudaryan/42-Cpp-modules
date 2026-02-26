#include "./Zombie.hpp"

int	degree(long n)
{
	int	deg;

	deg = 1;
	while (n / deg >= 10)
		deg *= 10;
	return (deg);
}

std::string	intToString(int num)
{
	std::string	str;
	int			deg;

	if (num < 0)
	{
		str += '-';
		num *= -1;
	}

	deg = degree(num);

	while (deg)
	{
		str += ((num / deg) + '0');
		num %= deg;
		deg /= 10;
	}

	return (str);
}

Zombie	*zombieHorde(int n, std::string name)
{
	if (n <= 0)
		return (NULL);

	Zombie	*zombies = new Zombie[n];

	for (int i = 0; i < n; ++i)
		zombies[i].setName(name + intToString(i));

	return (zombies);
}
