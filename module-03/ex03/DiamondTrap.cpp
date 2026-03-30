#include <iostream>
#include "./DiamondTrap.hpp"

/*DiamondTrap ctor/dtor*/
DiamondTrap::DiamondTrap() :
	ClapTrap("default_clap_name"),
	ScavTrap(),
	FragTrap(),
	name("default")
{
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->damagePoints = FragTrap::damagePoints;
}

DiamondTrap::DiamondTrap(const std::string& name) :
	ClapTrap(name + "_clap_name"),
	ScavTrap(name),
	FragTrap(name),
	name(name)
{
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->damagePoints = FragTrap::damagePoints;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) :
	ClapTrap(other),
	ScavTrap(other),
	FragTrap(other),
	name(other.name)
{}

DiamondTrap::~DiamondTrap()
{}


/*DiamondTrap operators*/
DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->name = other.name;
	}
	return (*this);
}

/*DiamondTrap methods*/
void	DiamondTrap::whoAmI(void)
{
	std::cout << "Diamond name: " << this->name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::name << std::endl;
}
