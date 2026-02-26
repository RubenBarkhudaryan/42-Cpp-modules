#ifndef	ZOMBIE_HPP

# define ZOMBIE_HPP

# include <string>

class	Zombie
{
	private:
		std::string	name;

	public:
		/*-----Zombie ctor/dtor-----*/
		Zombie(void);
		Zombie(const std::string& name);
		~Zombie(void);

		/*-----Zombie methods-----*/
		void	announce(void);
		void	setName(const std::string& name);
};

Zombie	*zombieHorde(int n, std::string name);

#endif //ZOMBIE_HPP