#ifndef MUTANT_STACK_HPP

# define MUTANT_STACK_HPP

# include <stack>
# include <deque>

template <typename T, typename Container = std::deque<T> >
class	MutantStack : public std::stack<T, Container>
{
	public:
		/*-----MutantStack ctors/dtor-----*/
		MutantStack();
		MutantStack(const MutantStack& other);
		~MutantStack();

		/*-----MutantStack ctors/dtor-----*/
		MutantStack&	operator=(const MutantStack& other);

		/*-----MutantStack iterators-----*/
		typedef typename	std::stack<T, Container>::container_type::iterator					iterator;
		typedef typename	std::stack<T, Container>::container_type::const_iterator			const_iterator;
		typedef typename	std::stack<T, Container>::container_type::reverse_iterator			reverse_iterator;
		typedef typename	std::stack<T, Container>::container_type::const_reverse_iterator	const_reverse_iterator;

		iterator				begin(void);
		iterator				end(void);

		const_iterator			cbegin(void) const;
		const_iterator			cend(void) const;

		reverse_iterator		rbegin(void);
		reverse_iterator		rend(void);

		const_reverse_iterator	crbegin(void) const;
		const_reverse_iterator	crend(void) const;
};

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack() : std::stack<T, Container>()
{}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack& other) : std::stack<T, Container>(other)
{}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack()
{}

template <typename T, typename Container>
MutantStack<T, Container>&	MutantStack<T, Container>::operator=(const MutantStack& other)
{
	std::stack<T, Container>::operator=(other);
	return (*this);
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator	MutantStack<T, Container>::begin(void)
{
	return (this->c.begin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator	MutantStack<T, Container>::end(void)
{
	return (this->c.end());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator	MutantStack<T, Container>::cbegin(void) const
{
	return (this->c.begin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator	MutantStack<T, Container>::cend(void) const
{
	return (this->c.end());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator	MutantStack<T, Container>::rbegin(void)
{
	return (this->c.rbegin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator	MutantStack<T, Container>::rend(void)
{
	return (this->c.rend());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator	MutantStack<T, Container>::crbegin(void) const
{
	return (this->c.rbegin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator	MutantStack<T, Container>::crend(void) const
{
	return (this->c.rend());
}

#endif //MUTANT_STACK_HPP