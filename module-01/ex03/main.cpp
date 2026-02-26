#include "./Weapon.hpp"
#include "./HumanA.hpp"
#include "./HumanB.hpp"

/*
//===========SUBJECT CASES============
int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return (0);
}
*/

#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
	std::cout << "========== BASIC TEST ==========\n";

	Weapon	club("crude spiked club");

	HumanA	bob("Bob", club);
	HumanB	jim("Jim");

	bob.attack();
	jim.attack();

	jim.setWeapon(club);
	jim.attack();

	std::cout << "\n========== CHANGE WEAPON TYPE ==========\n";

	club.setType("some other type of club");

	bob.attack();
	jim.attack();

	std::cout << "\n========== MULTIPLE HUMANS SAME WEAPON ==========\n";

	HumanA	alice("Alice", club);
	HumanB	tom("Tom");
	tom.setWeapon(club);

	alice.attack();
	tom.attack();

	std::cout << "\n========== REASSIGN WEAPON ==========\n";

	Weapon sword("long sword");
	tom.setWeapon(sword);

	tom.attack();
	sword.setType("enchanted sword");
	tom.attack();

	std::cout << "\n========== HUMAN WITHOUT WEAPON ==========\n";

	HumanB	noWeaponGuy("BareHands");
	noWeaponGuy.attack();

	std::cout << "\n========== DEFAULT CONSTRUCTORS ==========\n";

	HumanA	defaultA("Default Name", club);
	HumanB	defaultB;

	defaultA.attack();
	defaultB.attack();

	std::cout << "\n========== SCOPE TEST ==========\n";

	HumanB	scopedHuman("Scoped");

	{
		Weapon tempWeapon("temporary dagger");
		scopedHuman.setWeapon(tempWeapon);
		scopedHuman.attack();

		tempWeapon.setType("temporary dagger++");
		scopedHuman.attack();
	}

	// ⚠️ Dangerous — weapon is destroyed here
	std::cout << "Weapon went out of scope...\n";
	scopedHuman.attack();  // Undefined behavior possible!

	std::cout << "\n========== END ==========\n";

	return 0;
}