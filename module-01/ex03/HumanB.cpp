#include <iostream>
#include "./HumanB.hpp"

HumanB::HumanB(void) :
		name(""),
		weapon(NULL)
{}

HumanB::HumanB(const std::string& name) :
		name(name),
		weapon(NULL)
{}

HumanB::~HumanB(void)
{}

void	HumanB::attack(void)
{
	if (this->weapon)
	{
		std::cout << this->name
				<< " attacks with their "
				<< this->weapon->getType() << std::endl;
	}
	else
		std::cout << this->name << " attacks with bare hands" << std::endl;
}

void	HumanB::setWeapon(Weapon& wp)
{
	this->weapon = &wp;
}
