#include <iostream>
#include "./DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	diamond("DI4M0ND");

	std::cout << "\nTesting attack function" << std::endl;
	diamond.attack("target");

	std::cout << "\nTesting takeDamage function" << std::endl;
	diamond.takeDamage(20);

	std::cout << "\nTesting beRepaired function" << std::endl;
	diamond.beRepaired(50);

	std::cout << "\nCreating a second DiamondTrap object diamond2" << std::endl;
	DiamondTrap	diamond2("DI4M0ND2");

	std::cout << "\nTesting attack and takeDamage between diamond and diamond2" << std::endl;
	diamond.attack("DI4M0ND2");
	diamond2.takeDamage(25);

	std::cout << "\nCreating a third DiamondTrap object diamond3 (copy of diamond2)" << std::endl;
	DiamondTrap	diamond3 = diamond2;

	std::cout << "\nTesting attack and takeDamage between diamond2 and diamond3" << std::endl;
	diamond2.attack("DI4M0ND3");
	diamond3.takeDamage(20);

	std::cout << "\nCreating a fourth DiamondTrap object diamond4 (assigned from diamond)" << std::endl;
	DiamondTrap	diamond4("DI4M0ND4");
	diamond4 = diamond;

	std::cout << "\nTesting attack and takeDamage between diamond and diamond4" << std::endl;
	diamond.attack("DI4M0ND4");
	diamond4.takeDamage(50);

	std::cout << "\nTesting special functions, whoAmI and highFivesGuys" << std::endl;
	diamond.whoAmI();
	diamond.highFivesGuys();
	return (0);
}