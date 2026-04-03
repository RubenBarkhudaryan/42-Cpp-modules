#include "./Ice.hpp"
#include "./Cure.hpp"
#include "./MateriaSource.hpp"

/*MateriaSource ctors/dtor*/
MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; ++i)
		this->source[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < 4; ++i)
	{
		if (other.source[i])
			this->source[i] = other.source[i]->clone();
		else
			this->source[i] = NULL;
	}
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; ++i)
		delete this->source[i];
}


/*MateriaSource operators*/
MateriaSource&	MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; ++i)
			delete this->source[i];

		for (int i = 0; i < 4; ++i)
		{
			if (other.source[i])
				this->source[i] = other.source[i]->clone();
			else
				this->source[i] = NULL;
		}
	}
	return (*this);
}


/*MateriaSource methods*/
void	MateriaSource::learnMateria(AMateria *materia)
{
	if (!materia)
		return ;
	for (int i = 0; i < 4; ++i)
	{
		if (this->source[i] == NULL)
		{
			this->source[i] = materia->clone();
			delete materia; /*disagree with this line but it actually works*/
			return ;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (this->source[i] && this->source[i]->getType() == type)
			return (this->source[i]->clone());
	}
	return (NULL);
}
