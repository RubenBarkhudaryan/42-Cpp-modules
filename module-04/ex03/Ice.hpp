#ifndef ICE_HPP

# define ICE_HPP

# include "./AMateria.hpp"

class	Ice : public AMateria
{
	public:
		/*Ice ctors/dtor*/
		Ice();
		Ice(const Ice& other);
		~Ice(); /*override*/

		/*Ice operators*/
		Ice&		operator=(const Ice& other);

		/*Ice methods*/
		AMateria	*clone() const; /*override*/
		void		use(ICharacter &target); /*override*/
};

#endif //ICE_HPP