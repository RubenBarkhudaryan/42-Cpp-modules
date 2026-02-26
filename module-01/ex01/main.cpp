#include <iostream>
#include "./Zombie.hpp"

int	main()
{
	std::cout << "Creating horde of 5 zombies...\n";

	Zombie *zombies = zombieHorde(5, "Zombie_1");

	if (!zombies)
	{
		std::cout << "Failed to create horde\n";
		return (1);
	}

	std::cout << "\nAnnouncing horde:\n";
	for (int i = 0; i < 5; i++)
		zombies[i].announce();

	std::cout << "\nDeleting horde...\n";
	delete[] zombies;

	std::cout << "\nCreating horde of 1 zombie...\n";
	Zombie *zombies_2 = zombieHorde(1, "Zombie_2");
	zombies_2[0].announce();
	delete[] zombies_2;

	std::cout << "\nTesting zero or negative count...\n";
	Zombie *zombies_3 = zombieHorde(0, "Zombie_3");
	if (!zombies_3)
		std::cout << "Correct: returned NULL.\n";

	return (0);
}
