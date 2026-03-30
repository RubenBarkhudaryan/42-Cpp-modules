#include <iostream>
#include "./FragTrap.hpp"

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
		FragTrap	a;

		a.attack("enemy_1");
		a.takeDamage(10);
		a.beRepaired(5);
		a.highFivesGuys();
	}

	printTitle("PARAMETERIZED CONSTRUCTOR TEST");
	{
		FragTrap	b("Fraggy");

		b.attack("bandit");
		b.takeDamage(25);
		b.beRepaired(10);
		b.highFivesGuys();
	}

	printTitle("COPY CONSTRUCTOR TEST");
	{
		FragTrap	original("Original");

		original.attack("target_1");
		original.takeDamage(30);
		original.highFivesGuys();

		FragTrap	copy(original);

		copy.attack("target_2");
		copy.beRepaired(15);
		copy.highFivesGuys();
	}

	printTitle("ASSIGNMENT OPERATOR TEST");
	{
		FragTrap	left("Left");
		FragTrap	right("Right");

		left.takeDamage(40);
		left.attack("enemy_left");
		left.highFivesGuys();

		right = left;
		right.attack("enemy_right");
		right.beRepaired(20);
		right.highFivesGuys();
	}

	printTitle("BASIC ATTACK LOOP TEST");
	{
		FragTrap	c("Attacker");

		for (int i = 0; i < 5; i++)
			c.attack("dummy");
	}

	printTitle("ENERGY DEPLETION TEST");
	{
		FragTrap	d("NoEnergy");

		for (int i = 0; i < 105; i++)
			d.attack("wall");

		d.beRepaired(10);
		d.attack("last_try");
		d.highFivesGuys();
	}

	printTitle("TAKE DAMAGE TEST");
	{
		FragTrap	e("Tank");

		e.takeDamage(1);
		e.takeDamage(20);
		e.takeDamage(30);
		e.takeDamage(10);
		e.beRepaired(5);
	}

	printTitle("OVERKILL DAMAGE TEST");
	{
		FragTrap	f("Fragile");

		f.takeDamage(9999);
		f.attack("nobody");
		f.beRepaired(10);
		f.takeDamage(1);
		f.highFivesGuys();
	}

	printTitle("REPAIR LOOP TEST");
	{
		FragTrap	g("Medic");

		g.takeDamage(40);
		for (int i = 0; i < 10; i++)
			g.beRepaired(3);
	}

	printTitle("MIXED ACTION CHAIN TEST");
	{
		FragTrap	h("Hybrid");

		h.attack("enemy_a");
		h.attack("enemy_b");
		h.takeDamage(15);
		h.beRepaired(5);
		h.highFivesGuys();
		h.attack("enemy_c");
		h.takeDamage(50);
		h.beRepaired(10);
		h.highFivesGuys();
		h.attack("enemy_d");
	}

	printTitle("DEATH TEST");
	{
		FragTrap	i("DeadTrap");

		i.takeDamage(100);
		i.attack("ghost");
		i.beRepaired(10);
		i.takeDamage(1);
		i.highFivesGuys();
	}

	printTitle("SMALL DAMAGE UNTIL DEATH TEST");
	{
		FragTrap	j("SlowDeath");

		for (int i = 0; i < 20; i++)
			j.takeDamage(5);

		j.attack("after_death");
		j.beRepaired(1);
	}

	printTitle("ENERGY + REPAIR COMBINATION TEST");
	{
		FragTrap	k("Combo");

		for (int i = 0; i < 20; i++)
			k.beRepaired(1);
		for (int i = 0; i < 85; i++)
			k.attack("training_bot");

		k.beRepaired(5);
		k.attack("final_bot");
	}

	printTitle("HIGH FIVE STRESS TEST");
	{
		FragTrap	m("Friendly");

		for (int i = 0; i < 8; i++)
			m.highFivesGuys();
	}

	printTitle("COPY INDEPENDENCE TEST");
	{
		FragTrap	a("Alpha");

		a.takeDamage(20);
		a.highFivesGuys();

		FragTrap	b(a);

		a.attack("enemy_a");
		a.takeDamage(10);

		b.attack("enemy_b");
		b.beRepaired(20);
		b.highFivesGuys();
	}

	printTitle("ASSIGNMENT INDEPENDENCE TEST");
	{
		FragTrap	a("First");
		FragTrap	b("Second");

		a.takeDamage(35);
		a.highFivesGuys();
		b = a;

		a.attack("enemy_first");
		a.takeDamage(10);

		b.beRepaired(15);
		b.highFivesGuys();
		b.attack("enemy_second");
	}

	printTitle("LONG SURVIVAL TEST");
	{
		FragTrap	boss("Boss");

		boss.attack("hero");
		boss.takeDamage(10);
		boss.beRepaired(5);
		boss.attack("hero");
		boss.highFivesGuys();
		boss.takeDamage(20);
		boss.attack("hero");
		boss.beRepaired(15);
		boss.takeDamage(30);
		boss.attack("hero");
		boss.highFivesGuys();
		boss.takeDamage(40);
		boss.attack("hero");
		boss.beRepaired(10);
		boss.takeDamage(50);
		boss.attack("hero");
	}

	printTitle("END OF TESTS");
	return (0);
}