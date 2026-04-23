#ifndef SPAN_HPP

# define SPAN_HPP

# define SPAN_MAX_REACHED "Span exception: maximum count of elements reached"
# define SPAN_FEW_ELEMS "Span exception: too few elements to calculate shortest span"

# include <vector>

class	Span
{
	private:
		unsigned int		n;
		unsigned int		offset;
		std::vector<int>	data;

	public:
		/*-----Span ctors/dtor-----*/
		Span();
		Span(unsigned int n);
		Span(const Span& other);
		~Span();

		/*-----Span operators-----*/
		Span&	operator=(const Span& other);

		/*-----Span methods-----*/
		void	addNumber(int num);
		int		shortestSpan(void);
		int		longestSpan(void);

		template <typename T>
		void	insertRange(const T& start, const T& end)
		{
			for (T it = start; it != end; ++it)
				this->addNumber(*it);
		}
};

#endif //SPAN_HPP