#include "./RPN.hpp"
#include <stack>
#include <string>
#include <iostream>

/*-----RPN ctors/dtor-----*/
RPN::RPN()
{
}

RPN::RPN(const RPN &)
{
}

RPN::~RPN()
{
}

/*-----RPN operators-----*/
RPN	&RPN::operator=(const RPN &)
{
	return (*this);
}

static bool	inSet(const std::string& src, char target)
{
	for (std::size_t i = 0; i < src.size(); ++i)
	{
		if (src[i] == target)
			return (true);
	}
	return (false);
}

/*-----RPN methods-----*/
void	RPN::calculate(const std::string &input)
{
	std::stack<int>	rpn;

	for (std::size_t i = 0; i < input.size(); ++i)
	{
		if (input[i] >= '0' && input[i] <= '9')
			rpn.push(input[i] - '0');
		else if (inSet("+-*/", input[i]))
		{
			int	first = rpn.top();
			rpn.pop();
			int	second = rpn.top();
			rpn.pop();

			if (input[i] == '+')
				rpn.push(second + first);
			else if (input[i] == '-')
				rpn.push(second - first);
			else if (input[i] == '*')
				rpn.push(second * first);
			else if (input[i] == '/')
				rpn.push(second / first);
		}
	}
	std::cout << rpn.top() << std::endl;
}
