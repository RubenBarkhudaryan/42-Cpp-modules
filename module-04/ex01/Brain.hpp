#ifndef BRAIN_HPP

# define BRAIN_HPP

# include <string>

class	Brain
{
	private:
		std::string	ideas[100];

	public:
		/*Brain ctors/dtor*/
		Brain();
		Brain(const Brain& other);
		~Brain();

		/*Brain operators*/
		Brain&	operator=(const Brain& other);

		/*Brain methods*/
		Brain		*clone(void) const;
		std::string	getIdea(int idx) const;
		void		setIdea(int idx, const std::string& idea);
};

#endif //BRAIN_HPP