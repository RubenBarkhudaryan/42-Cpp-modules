#ifndef	WEAPON_HPP

# define WEAPON_HPP

# include <string>

class	Weapon
{
	private:
		std::string	type;

	public:
		/*-----Weapon ctor/dtor-----*/
		explicit Weapon(const std::string& type);
		Weapon(void);
		~Weapon(void);

		/*-----Weapon methods-----*/
		const std::string	&getType(void) const;
		void				setType(const std::string& type);
};

#endif //WEAPON_HPP
