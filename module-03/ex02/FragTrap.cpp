#include <iostream>
#include "./FragTrap.hpp"

/*FragTrap ctor/dtor*/
FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default ctor called" << std::endl;
}

FragTrap::FragTrap(const std::string& _name) : ClapTrap(_name)
{
	std::cout << "FragTrap parameterized ctor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->damagePoints = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap copy ctor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap dtor called" << std::endl;
}


/*FragTrap operators*/
FragTrap&	FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap copy assignment called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

/*FragTrap methods*/
void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap "
				<< this->name
				<< " high fives guys "
				<< std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (this->hitPoints == 0 || this->energyPoints == 0)
		return ;

	--(this->energyPoints);

	std::cout << "FragTrap "
				<< this->name << " attacks "
				<< target
				<< ", causing "
				<< this->damagePoints
				<< " points of damage!" << std::endl;
}

void	FragTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints == 0)
		return ;
	if (amount >= static_cast<unsigned int>(this->hitPoints))
		this->hitPoints = 0;
	else
		this->hitPoints -= amount;

	std::cout << "FragTrap " << this->name
				<< " takes damage of amount "
				<< amount << std::endl;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints == 0 || this->energyPoints == 0)
		return ;

	(this->energyPoints)--;
	this->hitPoints += amount;

	std::cout << "FragTrap " << this->name
				<< " repairs itself for "
				<< amount << " HP!" << std::endl;
}
