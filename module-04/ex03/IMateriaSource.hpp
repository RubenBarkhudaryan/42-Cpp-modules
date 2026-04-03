#ifndef I_MATERIA_SOURCE_HPP

# define I_MATERIA_SOURCE_HPP

# include "./AMateria.hpp"

class	IMateriaSource
{
	public:
		/*IMateriaSource dtor*/
		virtual ~IMateriaSource() {}

		/*IMateriaSource methods*/
		virtual void		learnMateria(AMateria*) = 0;
		virtual AMateria*	createMateria(std::string const & type) = 0;
};

#endif //I_MATERIA_SOURCE_HPP