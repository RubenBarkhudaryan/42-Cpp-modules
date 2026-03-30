#ifndef DIAMONDTRAP_HPP

# define DIAMONDTRAP_HPP

# include <string>
# include "./ClapTrap.hpp"
# include "./ScavTrap.hpp"
# include "./FragTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string	name;

	public:
		/*DiamondTrap ctor/dtor*/
		DiamondTrap();
		DiamondTrap(const std::string& name);
		DiamondTrap(const DiamondTrap& other);
		~DiamondTrap(); /*override*/

		/*DiamondTrap operators*/
		DiamondTrap&	operator=(const DiamondTrap& other);

		/*DiamondTrap methods*/
		void			whoAmI(void);
};

#endif //DIAMONDTRAP_HPP