#ifndef DOG_HPP

# define DOG_HPP

# include "./Brain.hpp"
# include "./Animal.hpp"

class	Dog : public Animal
{
	private:
		Brain	*brain;

	public:
		/*Dog ctors/dtor*/
		Dog();
		Dog(const Dog& other);
		~Dog(); /*override*/

		/*Dog operators*/
		Dog&	operator=(const Dog& other);

		/*Dog methods*/
		void		makeSound(void) const; /*override*/
		std::string	getIdea(int idx) const;
		void		setIdea(int idx, const std::string& idea);
};

#endif //DOG_HPP