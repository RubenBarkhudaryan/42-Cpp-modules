#include <iostream>
#include "./ClapTrap.hpp"

int	main(void)
{
	std::cout << "=== BASIC TEST ===" << std::endl;
	ClapTrap a("A");

	a.attack("Enemy");
	a.takeDamage(3);
	a.beRepaired(2);

	std::cout << "\n=== ENERGY DEPLETION ===" << std::endl;
	ClapTrap b("B");

	for (int i = 0; i < 11; i++)
		b.attack("Target");

	b.beRepaired(5);

	std::cout << "\n=== TAKING DAMAGE ===" << std::endl;
	ClapTrap c("C");

	c.takeDamage(5);
	c.takeDamage(10);

	std::cout << "\n=== DEAD CANNOT ACT ===" << std::endl;
	c.attack("Nobody");
	c.beRepaired(5);
	c.takeDamage(1);

	std::cout << "\n=== REPAIR TEST ===" << std::endl;
	ClapTrap d("D");

	d.takeDamage(5);
	d.beRepaired(3);
	d.beRepaired(10);

	std::cout << "\n=== ENERGY + REPAIR LIMIT ===" << std::endl;
	ClapTrap e("E");

	for (int i = 0; i < 5; i++)
		e.beRepaired(1);

	for (int i = 0; i < 6; i++)
		e.attack("Target");

	e.beRepaired(1);

	std::cout << "\n=== COPY CONSTRUCTOR ===" << std::endl;
	ClapTrap f("F");

	f.takeDamage(4);

	ClapTrap f_copy(f);
	f_copy.attack("Enemy");

	std::cout << "\n=== ASSIGNMENT OPERATOR ===" << std::endl;
	ClapTrap g("G");
	ClapTrap h("H");

	g.takeDamage(7);
	h = g;

	h.attack("Enemy");

	std::cout << "\n=== CHAIN TEST ===" << std::endl;
	ClapTrap x("X");

	x.attack("Enemy");
	x.takeDamage(3);
	x.attack("Enemy");
	x.beRepaired(2);
	x.attack("Enemy");
	x.takeDamage(20);
	x.beRepaired(5);

	return (0);
}