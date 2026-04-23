#include <iostream>
#include <list>
#include "./MutantStack.hpp"

static void	printTitle(const std::string& title)
{
	std::cout << "\n=== " << title << " ===" << std::endl;
}

static void	testSubjectExample(void)
{
	printTitle("Subject Example");
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "top: " << mstack.top() << " (expected 17)" << std::endl;

	mstack.pop();
	std::cout << "size after pop: " << mstack.size() << " (expected 1)" << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator	it = mstack.begin();
	MutantStack<int>::iterator	ite = mstack.end();

	std::cout << "forward iteration: ";
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
}

static void	testConstAndReverseIterators(void)
{
	printTitle("Const And Reverse Iterators");
	MutantStack<int>	mstack;

	for (int i = 1; i <= 5; ++i)
		mstack.push(i * 10);

	std::cout << "const forward iteration: ";
	MutantStack<int>::const_iterator	cit = mstack.cbegin();
	MutantStack<int>::const_iterator	cite = mstack.cend();
	while (cit != cite)
	{
		std::cout << *cit << " ";
		++cit;
	}
	std::cout << std::endl;

	std::cout << "reverse iteration: ";
	MutantStack<int>::reverse_iterator	rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator	rite = mstack.rend();
	while (rit != rite)
	{
		std::cout << *rit << " ";
		++rit;
	}
	std::cout << std::endl;

	std::cout << "const reverse iteration: ";
	MutantStack<int>::const_reverse_iterator	crit = mstack.crbegin();
	MutantStack<int>::const_reverse_iterator	crite = mstack.crend();
	while (crit != crite)
	{
		std::cout << *crit << " ";
		++crit;
	}
	std::cout << std::endl;
}

static void	testCopyAndAssignment(void)
{
	printTitle("Copy Constructor And Assignment");
	MutantStack<int>	original;
	original.push(10);
	original.push(20);
	original.push(30);

	MutantStack<int>	copy(original);
	MutantStack<int>	assigned;
	assigned = original;

	original.pop();
	original.push(99);

	std::cout << "original top: " << original.top() << " (expected 99)" << std::endl;
	std::cout << "copy top    : " << copy.top() << " (expected 30)" << std::endl;
	std::cout << "assigned top: " << assigned.top() << " (expected 30)" << std::endl;
}

static void	testAgainstList(void)
{
	printTitle("Comparison Against std::list");
	MutantStack<int>	mstack;
	std::list<int>	lst;

	for (int i = 0; i < 6; ++i)
	{
		mstack.push(i * 7);
		lst.push_back(i * 7);
	}

	MutantStack<int>::iterator	it = mstack.begin();
	std::list<int>::iterator		lit = lst.begin();
	bool	allEqual = true;

	while (it != mstack.end() && lit != lst.end())
	{
		if (*it != *lit)
		{
			allEqual = false;
			break ;
		}
		++it;
		++lit;
	}

	if (it != mstack.end() || lit != lst.end())
		allEqual = false;

	std::cout << "sequence equality with list: "
		<< (allEqual ? "OK" : "FAIL") << std::endl;
}

int	main(void)
{
	testSubjectExample();
	testConstAndReverseIterators();
	testCopyAndAssignment();
	testAgainstList();

	std::cout << "\nAll MutantStack tests executed." << std::endl;
	return (0);
}