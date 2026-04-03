#ifndef I_CHARACTER_HPP

# define I_CHARACTER_HPP

# include <string>

class	AMateria;

class	ICharacter
{
	public:
		/*ICharacter dtor*/
		virtual ~ICharacter() {};

		/*ICharacter methods*/
		virtual std::string const	&getName() const = 0;
		virtual void				equip(AMateria* materia) = 0;
		virtual void				unequip(int idx) = 0;
		virtual void				use(int idx, ICharacter& target) = 0;
};

#endif //I_CHARACTER_HPP