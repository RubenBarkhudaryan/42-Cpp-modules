#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	PmergeMe	pmerge;
	clock_t	start;
	clock_t	end;
	double	vectorTime;
	double	dequeTime;

	if (argc < 2)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}

	try
	{
		pmerge.parse(argv);

		pmerge.printBefore();

		start = clock();
		pmerge.sortVector(pmerge.getVector());
		end = clock();

		vectorTime = static_cast<double>(
			end - start) * 1000000.0 / CLOCKS_PER_SEC;

		start = clock();
		pmerge.sortDeque(pmerge.getDeque());
		end = clock();

		dequeTime = static_cast<double>(
			end - start) * 1000000.0 / CLOCKS_PER_SEC;

		pmerge.printAfter();

		std::cout
			<< "Time to process a range of "
			<< pmerge.getVector().size()
			<< " elements with std::vector : "
			<< vectorTime
			<< " us"
			<< std::endl;

		std::cout
			<< "Time to process a range of "
			<< pmerge.getDeque().size()
			<< " elements with std::deque : "
			<< dequeTime
			<< " us"
			<< std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}

	return (0);
}

