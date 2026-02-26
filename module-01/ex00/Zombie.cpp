#include <iostream>
#include "./Zombie.hpp"

Zombie::Zombie(void)
{
	this->name = "";
}

Zombie::Zombie(const std::string& name)
{
	this->name = name;
}

Zombie::~Zombie(void)
{
	std::cout << this->name << " destroyed." << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
