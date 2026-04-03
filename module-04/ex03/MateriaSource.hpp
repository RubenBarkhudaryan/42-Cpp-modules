#ifndef MATERIA_SOURCE_HPP

# define MATERIA_SOURCE_HPP

# include "./AMateria.hpp"
# include "./IMateriaSource.hpp"

class	MateriaSource : public IMateriaSource
{
	private:
		AMateria	*source[4];

	public:
		/*MateriaSource ctors/dtor*/
		MateriaSource();
		MateriaSource(const MateriaSource& other);
		~MateriaSource();

		/*MateriaSource operators*/
		MateriaSource&	operator=(const MateriaSource& other);

		/*MateriaSource methods*/
		void			learnMateria(AMateria *);
		AMateria*		createMateria(std::string const &type);
};

#endif //MATERIA_SOURCE_HPP