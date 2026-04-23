#include <iostream>
#include <string>
#include "./Array.hpp"

static void	printHeader(const std::string& title)
{
	std::cout << "\n===== " << title << " =====" << std::endl;
}

static void	printTestResult(const std::string& name, bool ok)
{
	std::cout << (ok ? "[PASS] " : "[FAIL] ") << name << std::endl;
}

int	main()
{
	bool	allPassed = true;

	printHeader("Default constructor");
	Array<int> empty;
	bool test = (empty.size() == 0);
	printTestResult("size() == 0 for default array", test);
	allPassed = allPassed && test;

	printHeader("Sized constructor and read/write");
	Array<int> numbers(5);
	for (unsigned int i = 0; i < numbers.size(); ++i)
		numbers[static_cast<int>(i)] = static_cast<int>(i) * 10;
	test = true;
	for (unsigned int i = 0; i < numbers.size(); ++i)
	{
		if (numbers[static_cast<int>(i)] != static_cast<int>(i) * 10)
			test = false;
	}
	printTestResult("stored values are correct", test);
	allPassed = allPassed && test;

	printHeader("Const indexing");
	const Array<int>& constNumbers = numbers;
	test = (constNumbers[3] == 30);
	printTestResult("const operator[] returns expected value", test);
	allPassed = allPassed && test;

	printHeader("Copy constructor (deep copy)");
	Array<int> copied(numbers);
	copied[0] = 999;
	test = (numbers[0] == 0) && (copied[0] == 999);
	printTestResult("source unchanged after modifying copy", test);
	allPassed = allPassed && test;

	printHeader("Assignment operator (deep copy)");
	Array<int> assigned;
	assigned = numbers;
	assigned[1] = 777;
	test = (numbers[1] == 10) && (assigned[1] == 777) && (assigned.size() == numbers.size());
	printTestResult("assigned array is independent", test);
	allPassed = allPassed && test;

	printHeader("Assignment from empty to non-empty");
	Array<int> nonEmpty(3);
	nonEmpty[0] = 1;
	nonEmpty[1] = 2;
	nonEmpty[2] = 3;
	nonEmpty = empty;
	test = (nonEmpty.size() == 0);
	printTestResult("becomes empty after assignment", test);
	allPassed = allPassed && test;

	printHeader("Self-assignment");
	numbers = numbers;
	test = (numbers.size() == 5 && numbers[2] == 20);
	printTestResult("self-assignment keeps content", test);
	allPassed = allPassed && test;

	printHeader("Out-of-bounds access");
	bool threwHigh = false;
	bool threwNegative = false;
	bool threwOnEmpty = false;

	try
	{
		numbers[5] = 1;
	}
	catch (const std::exception&)
	{
		threwHigh = true;
	}

	try
	{
		numbers[-1] = 1;
	}
	catch (const std::exception&)
	{
		threwNegative = true;
	}

	try
	{
		empty[0] = 1;
	}
	catch (const std::exception&)
	{
		threwOnEmpty = true;
	}

	printTestResult("throws for index == size", threwHigh);
	printTestResult("throws for negative index", threwNegative);
	printTestResult("throws when indexing empty array", threwOnEmpty);
	allPassed = allPassed && threwHigh && threwNegative && threwOnEmpty;

	printHeader("Template with std::string");
	Array<std::string> words(3);
	words[0] = "hello";
	words[1] = "dynamic";
	words[2] = "array";
	test = (words[0] == "hello" && words[1] == "dynamic" && words[2] == "array");
	printTestResult("works with non-primitive type", test);
	allPassed = allPassed && test;

	printHeader("Summary");
	if (allPassed)
	{
		std::cout << "All tests passed." << std::endl;
		return (0);
	}
	std::cout << "Some tests failed." << std::endl;
	return (1);
}
