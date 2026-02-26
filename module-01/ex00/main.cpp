#include <iostream>
#include "./Zombie.hpp"

int	main(void)
{
	Zombie	zombie("Zombie_1");

	Zombie	*z_ptr = newZombie("Zombie_2");

	zombie.announce();
	z_ptr->announce();

	randomChump("Zombie_3");

	delete z_ptr;

	return (0);
}