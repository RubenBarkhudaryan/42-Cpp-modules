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

bool	inSet(const std::string& set, char target)
{
	return (set.find(target) != std::string::npos);
}

/*-----RPN methods-----*/
void	RPN::calculate(const std::string &input)
{
	std::stack<int>	rpn;

	for (std::size_t i = 0; i < input.size(); ++i)
	{
		if (input[i] == ' ')
			continue ;

		if (isdigit(input[i]))
		{
			if (i + 1 < input.size() && isdigit(input[i + 1]))
				throw std::runtime_error("Error");
			rpn.push(input[i] - '0');
		}
		else if (inSet("+-*/", input[i]))
		{
			if (rpn.size() < 2)
				throw std::runtime_error("Error");

			int first = rpn.top();
			rpn.pop();

			int second = rpn.top();
			rpn.pop();

			if (input[i] == '+')
				rpn.push(second + first);
			else if (input[i] == '-')
				rpn.push(second - first);
			else if (input[i] == '*')
				rpn.push(second * first);
			else
			{
				if (first == 0)
					throw std::runtime_error("Error");
				rpn.push(second / first);
			}
		}
		else
			throw std::runtime_error("Error");
	}
	if (rpn.size() != 1)
		throw std::runtime_error("Error");

	std::cout << rpn.top() << std::endl;
}
