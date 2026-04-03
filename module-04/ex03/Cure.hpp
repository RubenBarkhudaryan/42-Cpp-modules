#ifndef CURE_HPP

# define CURE_HPP

# include "./AMateria.hpp"

class	Cure : public AMateria
{
	public:
		/*Cure ctors/dtor*/
		Cure();
		Cure(const Cure& other);
		~Cure(); /*override*/

		/*Cure operators*/
		Cure&		operator=(const Cure& other);

		/*Cure methods*/
		AMateria	*clone() const; /*override*/
		void		use(ICharacter &target); /*override*/
};

#endif //CURE_HPP