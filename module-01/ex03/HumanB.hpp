#ifndef	HUMAN_B_HPP

# define HUMAN_B_HPP

# include <string>
# include "./Weapon.hpp"

class	HumanB
{
	private:
		std::string	name;
		Weapon		*weapon;

	public:
		/*-----HumanB ctor/dtor-----*/
		HumanB(void);
		HumanB(const std::string& name);
		~HumanB(void);

		/*-----HumanB ctor/dtor-----*/
		void	attack(void);
		void	setWeapon(Weapon& wp);
};

#endif //HUMAN_B_HPP
