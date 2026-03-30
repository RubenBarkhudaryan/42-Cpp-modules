#ifndef FRAGTRAP_HPP

# define FRAGTRAP_HPP

# include <string>
# include "./ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap
{
	public:
		/*FragTrap ctor/dtor*/
		FragTrap();
		FragTrap(const std::string& _name);
		FragTrap(const FragTrap& other);
		~FragTrap(); /*override*/

		/*FragTrap operators*/
		FragTrap&	operator=(const FragTrap& other);

		/*FragTrap methods*/
		void		highFivesGuys(void);
};

#endif //FRAGTRAP_HPP