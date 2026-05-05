#ifndef RPN_HPP

# define RPN_HPP

# include <stack>
# include <string>

class	RPN
{
	public:
		/*-----RPN ctors/dtor-----*/
		RPN();
		RPN(const RPN&);
		~RPN();

		/*-----RPN operators-----*/
		RPN&			operator=(const RPN&);

		/*-----RPN methods-----*/
		void			calculate(const std::string& input);
};

#endif //RPN_HPP