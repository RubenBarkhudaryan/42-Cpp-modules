#ifndef WRONG_ANIMAL_HPP

# define WRONG_ANIMAL_HPP

# include <string>

class	WrongAnimal
{
	protected:
		std::string	type;

	public:
		/*WrongAnimal ctors/dtor*/
		WrongAnimal();
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal(const std::string& type);
		~WrongAnimal();

		/*WrongAnimal operators*/
		WrongAnimal&	operator=(const WrongAnimal& other);

		/*WrongAnimal methods*/
		std::string		getType(void) const;
		void			makeSound(void) const;
};

#endif //WRONG_ANIMAL_HPP