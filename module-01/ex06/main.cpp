#include "./Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		Harl	harl;
		harl.complain(argv[1]);
	}
	else
		std::cout << "Program usage: [executable] [complaining word (DEBUG, INFO, WARNING, ERROR or other)]" << std::endl;
	return (0);
}