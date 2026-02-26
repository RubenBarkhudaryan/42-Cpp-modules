#include <iostream>
#include "./Zombie.hpp"

Zombie	*newZombie(std::string name)
{
	Zombie	*z_ptr;

	z_ptr = new Zombie(name);
	return (z_ptr);
}
