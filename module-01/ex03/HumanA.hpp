#ifndef	HUMAN_A_HPP

# define HUMAN_A_HPP

# include <string>
# include "./Weapon.hpp"

class	HumanA
{
	private:
		std::string	name;
		Weapon		&weapon;

	public:
		/*-----HumanA ctor/dtor-----*/
		HumanA(const std::string& name, Weapon& wp);
		~HumanA(void);

		/*-----HumanA ctor/dtor-----*/
		void	attack(void);
		void	setWeapon(Weapon& wp);
};

#endif //HUMAN_A_HPP
