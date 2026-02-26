#include <iostream>
#include "./HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& wp) :
		name(name),
		weapon(wp)
{}

HumanA::~HumanA(void)
{}

void	HumanA::attack(void)
{

	std::cout << this->name
			<< " attacks with their "
			<< this->weapon.getType() << std::endl;
}

void	HumanA::setWeapon(Weapon& wp)
{
	this->weapon = wp;
}
