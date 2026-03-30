#ifndef SCAVTRAP_HPP

# define SCAVTRAP_HPP

# include <string>
# include "./ClapTrap.hpp"

class	ScavTrap : public ClapTrap
{
	private:
		bool	mode;

	public:

		/*ScavTrap ctor/dtor*/
		ScavTrap();
		ScavTrap(const std::string& _name);
		ScavTrap(const ScavTrap& other);
		~ScavTrap(); /*override*/

		/*ScavTrap operators*/
		ScavTrap&	operator=(const ScavTrap& other);

		/*ScavTrap methods*/
		void		guardGate(void);
		void		attack(const std::string& target); /*override*/
};

#endif //SCAVTRAP_HPP