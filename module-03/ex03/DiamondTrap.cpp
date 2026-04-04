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
	std::cout << "DiamondTrap default ctor called" << std::endl;
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
	std::cout << "DiamondTrap parameterized ctor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) :
	ClapTrap(other),
	ScavTrap(other),
	FragTrap(other),
	name(other.name)
{
	std::cout << "DiamondTrap copy ctor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap dtor called" << std::endl;
}


/*DiamondTrap operators*/
DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
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
