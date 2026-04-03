#ifndef CAT_HPP

# define CAT_HPP

# include "./Brain.hpp"
# include "./Animal.hpp"

class	Cat : public Animal
{
	private:
		Brain	*brain;

	public:
		/*Cat ctors/dtor*/
		Cat();
		Cat(const Cat& other);
		~Cat(); /*override*/

		/*Cat operators*/
		Cat&	operator=(const Cat& other);

		/*Cat methods*/
		void		makeSound(void) const; /*override*/
		std::string	getIdea(int idx) const;
		void		setIdea(int idx, const std::string& idea);
};

#endif //CAT_HPP