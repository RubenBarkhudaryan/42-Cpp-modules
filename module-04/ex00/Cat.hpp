#ifndef CAT_HPP

# define CAT_HPP

# include "./Animal.hpp"

class	Cat : public Animal
{
	public:
		/*Cat ctors/dtor*/
		Cat();
		Cat(const Cat& other);
		~Cat(); /*override*/

		/*Cat operators*/
		Cat&	operator=(const Cat& other);

		/*Cat methods*/
		void	makeSound(void) const; /*override*/
};

#endif //CAT_HPP