#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>
#include "./Span.hpp"

static void	printSection(const std::string& title)
{
	std::cout << "\n=== " << title << " ===" << std::endl;
}

static void	testSubjectExample(void)
{
	printSection("Subject Example");
	Span	sp(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "shortestSpan: " << sp.shortestSpan() << " (expected 2)" << std::endl;
	std::cout << "longestSpan : " << sp.longestSpan() << " (expected 14)" << std::endl;
}

static void	testTooFewElements(void)
{
	printSection("Too Few Elements");
	Span	empty(5);
	Span	one(5);
	one.addNumber(42);

	try
	{
		empty.shortestSpan();
		std::cout << "ERROR: expected exception on empty.shortestSpan()" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "empty.shortestSpan() threw: " << e.what() << std::endl;
	}

	try
	{
		one.longestSpan();
		std::cout << "ERROR: expected exception on one.longestSpan()" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "one.longestSpan() threw  : " << e.what() << std::endl;
	}
}

static void	testFullSpanOverflow(void)
{
	printSection("Capacity Overflow");
	Span	sp(3);

	sp.addNumber(10);
	sp.addNumber(20);
	sp.addNumber(30);
	try
	{
		sp.addNumber(40);
		std::cout << "ERROR: expected exception on add beyond capacity" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "addNumber overflow threw : " << e.what() << std::endl;
	}
}

static void	testDuplicatesAndNegatives(void)
{
	printSection("Duplicates And Negatives");
	Span	sp(6);

	sp.addNumber(-10);
	sp.addNumber(-3);
	sp.addNumber(4);
	sp.addNumber(4);
	sp.addNumber(9);
	sp.addNumber(15);

	std::cout << "shortestSpan: " << sp.shortestSpan() << " (expected 0)" << std::endl;
	std::cout << "longestSpan : " << sp.longestSpan() << " (expected 25)" << std::endl;
}

static void	testInsertRangeWithVector(void)
{
	printSection("insertRange With std::vector");
	std::vector<int>	values;
	values.push_back(100);
	values.push_back(50);
	values.push_back(150);
	values.push_back(51);

	Span	sp(4);
	sp.insertRange(values.begin(), values.end());

	std::cout << "shortestSpan: " << sp.shortestSpan() << " (expected 1)" << std::endl;
	std::cout << "longestSpan : " << sp.longestSpan() << " (expected 100)" << std::endl;
}

static void	testInsertRangeOverflow(void)
{
	printSection("insertRange Overflow");
	std::list<int>	values;
	values.push_back(1);
	values.push_back(2);
	values.push_back(3);
	values.push_back(4);

	Span	sp(3);
	try
	{
		sp.insertRange(values.begin(), values.end());
		std::cout << "ERROR: expected exception in insertRange overflow" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "insertRange overflow threw: " << e.what() << std::endl;
	}
}

static void	testCopyAndAssignment(void)
{
	printSection("Copy Constructor And Assignment");
	Span	original(5);
	original.addNumber(7);
	original.addNumber(1);
	original.addNumber(20);

	Span	copy(original);
	Span	assigned(5);
	assigned = original;

	original.addNumber(99);

	std::cout << "copy.longestSpan    : " << copy.longestSpan() << " (expected 19)" << std::endl;
	std::cout << "assigned.longestSpan: " << assigned.longestSpan() << " (expected 19)" << std::endl;
	std::cout << "original.longestSpan: " << original.longestSpan() << " (expected 98)" << std::endl;
}

int	main(void)
{
	testSubjectExample();
	testTooFewElements();
	testFullSpanOverflow();
	testDuplicatesAndNegatives();
	testInsertRangeWithVector();
	testInsertRangeOverflow();
	testCopyAndAssignment();

	std::cout << "\nAll test sections executed." << std::endl;
	return (0);
}
