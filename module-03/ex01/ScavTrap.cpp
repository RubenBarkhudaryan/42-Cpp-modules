#include <iostream>
#include "./ScavTrap.hpp"

/*ScavTrap ctor/dtor*/
ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default ctor called" << std::endl;
	this->name = "default";
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->damagePoints = 20;
	this->mode = false;
}

ScavTrap::ScavTrap(const std::string &_name) : ClapTrap(_name)
{
	std::cout << "ScavTrap parameterized ctor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->damagePoints = 20;
	this->mode = false;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy ctor called" << std::endl;
	this->mode = other.mode;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap dtor called" << std::endl;
}

/*ScavTrap operator*/
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap copy assignment operator called\n";
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->mode = other.mode;
	}
	return (*this);
}

/*ScavTrap methods*/
void	ScavTrap::guardGate(void)
{
	if (this->hitPoints == 0 || this->energyPoints == 0)
		return ;
	if (!this->mode)
	{
		this->mode = true;
		std::cout << "ScavTrap "
					<< this->name
					<< " is now in Gate keeper mode"
					<< std::endl;
	}
	else
	{
		this->mode = false;
		std::cout << "ScavTrap "
					<< this->name
					<< " quit from Gate keeper mode"
					<< std::endl;
	}
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->hitPoints == 0 || this->energyPoints == 0)
		return ;

	--(this->energyPoints);

	std::cout << "ScavTrap "
				<< this->name << " attacks "
				<< target
				<< ", causing "
				<< this->damagePoints
				<< " points of damage!" << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints == 0)
		return ;
	if (amount >= static_cast<unsigned int>(this->hitPoints))
		this->hitPoints = 0;
	else
		this->hitPoints -= amount;

	std::cout << "ScavTrap " << this->name
				<< " takes damage of amount "
				<< amount << std::endl;
	
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints == 0 || this->energyPoints == 0)
		return ;

	(this->energyPoints)--;
	this->hitPoints += amount;

	std::cout << "ScavTrap " << this->name
				<< " repairs itself for "
				<< amount << " HP!" << std::endl;
}
