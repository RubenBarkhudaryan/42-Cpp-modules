#ifndef CLAPTRAP_HPP

# define CLAPTRAP_HPP

# include <string>

class	ClapTrap
{
	protected:
		std::string	name;

		int			hitPoints;
		int			energyPoints;
		int			damagePoints;

	public:

		/*ClapTrap ctor/dtor*/
		ClapTrap();
		ClapTrap(const std::string& _name);
		ClapTrap(const ClapTrap& other);
		virtual ~ClapTrap();

		/*ClapTrap operators*/
		ClapTrap&		operator=(const ClapTrap& other);

		/*ClapTrap methods*/
		virtual void	attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
};

#endif //CLAPTRAP_HPP