#ifndef A_MATERIA_HPP

# define A_MATERIA_HPP

# include <string>
# include "./ICharacter.hpp"

class	AMateria
{
	protected:
		std::string	type;

	public:
		/*AMateria ctors/dtor*/
		AMateria(const AMateria& other);
		AMateria(std::string const &type);
		virtual ~AMateria();

		/*AMateria operators*/
		AMateria&			operator=(const AMateria& other);

		/*AMateria methods*/
		std::string const	&getType() const;
		virtual AMateria	*clone() const = 0;
		virtual void		use(ICharacter &target);
};

#endif //A_MATERIA_HPP