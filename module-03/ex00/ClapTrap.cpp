#include <iostream>
#include "./ClapTrap.hpp"

/*ClapTrap ctor/dtor*/
ClapTrap::ClapTrap() :
	name("default"),
	hitPoints(10),
	energyPoints(10),
	damagePoints(0)
{
	std::cout << "ClapTrap default ctor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& _name) :
	name(_name),
	hitPoints(10),
	energyPoints(10),
	damagePoints(0)
{
	std::cout << "ClapTrap parameterized ctor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) :
	name(other.name),
	hitPoints(other.hitPoints),
	energyPoints(other.energyPoints),
	damagePoints(other.damagePoints)
{
	std::cout << "ClapTrap copy ctor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap dtor called" << std::endl;
}


/*ClapTrap operators*/
ClapTrap&	ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->damagePoints = other.damagePoints;
	}
	return (*this);
}


/*ClapTrap methods*/
void	ClapTrap::attack(const std::string& target)
{
	if (this->hitPoints == 0 || this->energyPoints == 0)
		return ;

	--(this->energyPoints);

	std::cout << "ClapTrap "
				<< this->name << " attacks "
				<< target
				<< ", causing "
				<< this->damagePoints
				<< " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints == 0)
		return ;
	if (amount >= static_cast<unsigned int>(this->hitPoints))
		this->hitPoints = 0;
	else
		this->hitPoints -= amount;

	std::cout << this->name
				<< " takes damage of amount "
				<< amount << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints == 0 || this->energyPoints == 0)
		return ;

	(this->energyPoints)--;
	this->hitPoints += amount;

	std::cout << this->name
				<< " repairs itself for "
				<< amount << " HP!" << std::endl;
}
