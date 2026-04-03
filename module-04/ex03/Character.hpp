#ifndef CHARACTER_HPP

# define CHARACTER_HPP

# include <string>
# include "./AMateria.hpp"
# include "./ICharacter.hpp"

class	Character : public ICharacter
{
	private:
		std::string	name;
		AMateria	*slots[4];

	public:
		/*Character ctors/dtor*/
		Character(const std::string& name);
		Character(const Character& other);
		~Character(); /*override*/

		/*Character operators*/
		Character&			operator=(const Character& other);

		/*Character methods*/
		std::string const	&getName() const;
		void				equip(AMateria* materia); /*override*/
		void				unequip(int idx); /*override*/
		void				use(int idx, ICharacter& target); /*override*/
};

#endif //CHARACTER_HPP