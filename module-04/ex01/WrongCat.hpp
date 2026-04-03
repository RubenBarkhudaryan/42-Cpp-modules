#ifndef WRONG_CAT_HPP

# define WRONG_CAT_HPP

# include "./WrongAnimal.hpp"

class	WrongCat : public WrongAnimal
{
	public:
		/*WrongCat ctors/dtor*/
		WrongCat();
		WrongCat(const WrongCat& other);
		~WrongCat();

		/*WrongCat operators*/
		WrongCat&	operator=(const WrongCat& other);

		/*WrongCat methods*/
		void		makeSound(void) const;
};

#endif //WRONG_CAT_HPP