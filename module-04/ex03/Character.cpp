#include <iostream>
#include "./Character.hpp"

/*Character ctors/dtor*/
Character::Character(const std::string& name) : name(name)
{
	for (int i = 0; i < 4; ++i)
		this->slots[i] = NULL;
}

Character::Character(const Character& other) : name(other.name)
{
	for (int i = 0; i < 4; ++i)
	{
		if (other.slots[i] != NULL)
			this->slots[i] = other.slots[i]->clone();
		else
			this->slots[i] = NULL;
	}
}

Character::~Character()
{
	for (int i = 0; i < 4; ++i)
	{
		if (this->slots[i])
			delete this->slots[i];
	}
}


/*Character operators*/
Character&	Character::operator=(const Character& other)
{
	if (this != &other)
	{
		this->name = other.name;
		for (int i = 0; i < 4; ++i)
			delete this->slots[i];
		for (int i = 0; i < 4; ++i)
		{
			if (other.slots[i] != NULL)
				this->slots[i] = other.slots[i]->clone();
			else
				this->slots[i] = NULL;
		}
	}
	return (*this);
}


/*Character methods*/
std::string const	&Character::getName() const
{
	return (this->name);
}

void	Character::equip(AMateria* materia)
{
	if (materia == NULL)
		return ;
	for (int i = 0; i < 4; ++i)
	{
		if (this->slots[i] == materia)
			return ;
		if (this->slots[i] == NULL)
		{
			this->slots[i] = materia;
			return ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return ;
	this->slots[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		return ;
	if (this->slots[idx] == NULL)
		return ;
	this->slots[idx]->use(target);
}
