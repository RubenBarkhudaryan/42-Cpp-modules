#include <deque>
#include <vector>
#include "./PmergeMe.hpp"

/*-----PmergeMe ctors/dtor-----*/
PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe&)
{
}

PmergeMe::~PmergeMe()
{
}

/*-----PmergeMe operators-----*/
PmergeMe	&PmergeMe::operator=(const PmergeMe&)
{
	return (*this);
}

int	PmergeMe::parseInt(const std::string& str)
{
	char*	end;
	long	value;

	if (str.empty())
		throw std::runtime_error("Error");

	value = std::strtol(str.c_str(), &end, 10);

	if (*end)
		throw std::runtime_error("Error");

	if (value <= 0)
		throw std::runtime_error("Error");

	if (value > INT_MAX)
		throw std::runtime_error("Error");

	return static_cast<int>(value);
}

void	PmergeMe::parse(char **argv)
{
	for (int i = 1; argv[i]; ++i)
	{
		int value = parseInt(argv[i]);

		_vector.push_back(value);
		_deque.push_back(value);
	}

	if (_vector.empty())
		throw std::runtime_error("Error");
}

void	PmergeMe::printBefore(void) const
{
	std::cout << "Before: ";

	for (std::size_t i = 0; i < _vector.size(); ++i)
		std::cout << _vector[i] << " ";

	std::cout << std::endl;
}

void	PmergeMe::printAfter(void) const
{
	std::cout << "After: ";

	for (std::size_t i = 0; i < _vector.size(); ++i)
		std::cout << _vector[i] << " ";

	std::cout << std::endl;
}

std::vector<int>&	PmergeMe::getVector(void)
{
	return (_vector);
}

std::deque<int>&	PmergeMe::getDeque(void)
{
	return (_deque);
}

void	PmergeMe::insertVector(
	std::vector<int>& vec,
	int value)
{
	std::vector<int>::iterator	pos;

	pos = std::lower_bound(
		vec.begin(),
		vec.end(),
		value);

	vec.insert(pos, value);
}

void	PmergeMe::insertDeque(
	std::deque<int>& deq,
	int value)
{
	std::deque<int>::iterator	pos;

	pos = std::lower_bound(
		deq.begin(),
		deq.end(),
		value);

	deq.insert(pos, value);
}

void PmergeMe::sortVector(std::vector<int>& vec)
{
	if (vec.size() <= 1)
		return ;

	std::vector<int>	big;
	std::vector<int>	small;

	for (std::size_t i = 0; i + 1 < vec.size(); i += 2)
	{
		if (vec[i] < vec[i + 1])
		{
			small.push_back(vec[i]);
			big.push_back(vec[i + 1]);
		}
		else
		{
			small.push_back(vec[i + 1]);
			big.push_back(vec[i]);
		}
	}

	bool odd = vec.size() % 2;
	int leftover = 0;

	if (odd)
		leftover = vec.back();

	sortVector(big);

	vec = big;

	for (std::size_t i = 0; i < small.size(); ++i)
		insertVector(vec, small[i]);

	if (odd)
		insertVector(vec, leftover);
}

void	PmergeMe::sortDeque(std::deque<int>& deq)
{
	if (deq.size() <= 1)
		return ;

	std::deque<int>	big;
	std::deque<int>	small;

	for (std::size_t i = 0; i + 1 < deq.size(); i += 2)
	{
		if (deq[i] < deq[i + 1])
		{
			small.push_back(deq[i]);
			big.push_back(deq[i + 1]);
		}
		else
		{
			small.push_back(deq[i + 1]);
			big.push_back(deq[i]);
		}
	}

	bool odd = deq.size() % 2;
	int leftover = 0;

	if (odd)
		leftover = deq.back();

	sortDeque(big);

	deq = big;

	for (std::size_t i = 0; i < small.size(); ++i)
		insertDeque(deq, small[i]);

	if (odd)
		insertDeque(deq, leftover);
}
