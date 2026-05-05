// static bool	isValidInput(const std::string& input);

#include "./RPN.hpp"

int	main()
{
	RPN	rpn;

	rpn.calculate("8 9 * 9 - 9 - 9 - 4 - 1 +");
}