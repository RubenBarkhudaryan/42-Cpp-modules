#ifndef FRAGTRAP_HPP

# define FRAGTRAP_HPP

# include <string>
# include "./ClapTrap.hpp"

class	FragTrap : public ClapTrap
{
	public:
		/*FragTrap ctor/dtor*/
		FragTrap();
		FragTrap(const std::string& _name);
		FragTrap(const FragTrap& other);
		~FragTrap();

		/*FragTrap operators*/
		FragTrap&	operator=(const FragTrap& other);

		/*FragTrap methods*/
		void		highFivesGuys(void);
		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
};

#endif //FRAGTRAP_HPP