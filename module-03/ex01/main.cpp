#include <iostream>
#include "./ScavTrap.hpp"

static void	printTitle(const std::string& title)
{
	std::cout << "\n========================================\n";
	std::cout << title << std::endl;
	std::cout << "========================================\n";
}

int	main(void)
{
	printTitle("DEFAULT CONSTRUCTOR TEST");
	{
		ScavTrap	a;

		a.attack("enemy_1");
		a.takeDamage(10);
		a.beRepaired(5);
		a.guardGate();
		a.guardGate();
	}

	printTitle("PARAMETERIZED CONSTRUCTOR TEST");
	{
		ScavTrap	b("Bender");

		b.attack("bandit");
		b.takeDamage(25);
		b.beRepaired(10);
		b.guardGate();
	}

	printTitle("COPY CONSTRUCTOR TEST");
	{
		ScavTrap	original("Original");

		original.attack("target_1");
		original.takeDamage(30);
		original.guardGate();

		ScavTrap	copy(original);

		copy.attack("target_2");
		copy.beRepaired(15);
		copy.guardGate();
	}

	printTitle("ASSIGNMENT OPERATOR TEST");
	{
		ScavTrap	left("Left");
		ScavTrap	right("Right");

		left.takeDamage(40);
		left.guardGate();
		left.attack("enemy_left");

		right = left;
		right.attack("enemy_right");
		right.beRepaired(20);
		right.guardGate();
	}

	printTitle("BASIC ATTACK LOOP TEST");
	{
		ScavTrap	c("Attacker");

		for (int i = 0; i < 5; i++)
			c.attack("dummy");
	}

	printTitle("ENERGY DEPLETION TEST");
	{
		ScavTrap	d("NoEnergy");

		for (int i = 0; i < 55; i++)
			d.attack("wall");

		d.beRepaired(10);
		d.attack("last_try");
		d.guardGate();
	}

	printTitle("TAKE DAMAGE TEST");
	{
		ScavTrap	e("Tank");

		e.takeDamage(1);
		e.takeDamage(20);
		e.takeDamage(30);
		e.takeDamage(10);
		e.beRepaired(5);
	}

	printTitle("OVERKILL DAMAGE TEST");
	{
		ScavTrap	f("Fragile");

		f.takeDamage(9999);
		f.attack("nobody");
		f.beRepaired(10);
		f.takeDamage(1);
		f.guardGate();
	}

	printTitle("REPAIR LOOP TEST");
	{
		ScavTrap	g("Medic");

		g.takeDamage(40);
		for (int i = 0; i < 10; i++)
			g.beRepaired(3);
	}

	printTitle("MIXED ACTION CHAIN TEST");
	{
		ScavTrap	h("Hybrid");

		h.attack("enemy_a");
		h.attack("enemy_b");
		h.takeDamage(15);
		h.beRepaired(5);
		h.guardGate();
		h.attack("enemy_c");
		h.takeDamage(50);
		h.beRepaired(10);
		h.guardGate();
		h.attack("enemy_d");
	}

	printTitle("DEATH TEST");
	{
		ScavTrap	i("DeadTrap");

		i.takeDamage(100);
		i.attack("ghost");
		i.beRepaired(10);
		i.takeDamage(1);
		i.guardGate();
	}

	printTitle("SMALL DAMAGE UNTIL DEATH TEST");
	{
		ScavTrap	j("SlowDeath");

		for (int i = 0; i < 20; i++)
			j.takeDamage(5);

		j.attack("after_death");
		j.beRepaired(1);
	}

	printTitle("ENERGY + REPAIR COMBINATION TEST");
	{
		ScavTrap	k("Combo");

		for (int i = 0; i < 20; i++)
			k.beRepaired(1);
		for (int i = 0; i < 35; i++)
			k.attack("training_bot");

		k.beRepaired(5);
		k.attack("final_bot");
	}

	printTitle("GUARD GATE TOGGLE STRESS TEST");
	{
		ScavTrap	m("GateKeeper");

		for (int i = 0; i < 8; i++)
			m.guardGate();
	}

	printTitle("COPY INDEPENDENCE TEST");
	{
		ScavTrap	a("Alpha");

		a.takeDamage(20);
		a.guardGate();

		ScavTrap	b(a);

		a.attack("enemy_a");
		a.takeDamage(10);
		a.guardGate();

		b.attack("enemy_b");
		b.beRepaired(20);
		b.guardGate();
	}

	printTitle("ASSIGNMENT INDEPENDENCE TEST");
	{
		ScavTrap	a("First");
		ScavTrap	b("Second");

		a.takeDamage(35);
		a.guardGate();
		b = a;

		a.attack("enemy_first");
		a.takeDamage(10);

		b.beRepaired(15);
		b.guardGate();
		b.attack("enemy_second");
	}

	printTitle("LONG SURVIVAL TEST");
	{
		ScavTrap	boss("Boss");

		boss.attack("hero");
		boss.takeDamage(10);
		boss.beRepaired(5);
		boss.attack("hero");
		boss.guardGate();
		boss.takeDamage(20);
		boss.attack("hero");
		boss.beRepaired(15);
		boss.takeDamage(30);
		boss.attack("hero");
		boss.guardGate();
		boss.takeDamage(40);
		boss.attack("hero");
		boss.beRepaired(10);
		boss.takeDamage(50);
		boss.attack("hero");
	}

	printTitle("END OF TESTS");
	return (0);
}