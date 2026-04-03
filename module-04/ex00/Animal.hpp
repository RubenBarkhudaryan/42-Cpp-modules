#ifndef ANIMAL_HPP

# define ANIMAL_HPP

# include <string>

class	Animal
{
	protected:
		std::string	type;

	public:
		/*Animal ctors/dtor*/
		Animal();
		Animal(const Animal& other);
		Animal(const std::string& type);
		virtual ~Animal();

		/*Animal operators*/
		Animal&			operator=(const Animal& other);

		/*Animal methods*/
		std::string		getType(void) const;
		virtual void	makeSound(void) const;
};

#endif //ANIMAL_HPP