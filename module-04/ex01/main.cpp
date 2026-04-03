#include <iostream>
#include "./Animal.hpp"
#include "./Dog.hpp"
#include "./Cat.hpp"

static void	test_basic(void)
{
	std::cout << "========== BASIC TEST ==========\n";

	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << "\n----- Types -----\n";
	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;

	std::cout << "\n----- Sounds -----\n";
	dog->makeSound();
	cat->makeSound();

	std::cout << "\n----- Deleting through Animal* -----\n";
	delete dog;
	delete cat;
}

static void	test_array(void)
{
	std::cout << "\n========== ARRAY TEST ==========\n";

	const int size = 4;
	Animal* animals[size];

	for (int i = 0; i < size; i++)
	{
		if (i < size / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << "\n----- Deleting array -----\n";
	for (int i = 0; i < size; i++)
		delete animals[i];
}

static void	test_deep_copy(void)
{
	std::cout << "\n========== DEEP COPY TEST ==========\n";

	Dog original;
	original.setIdea(0, "I want food");
	original.setIdea(1, "I want to sleep");

	Dog copy(original);
	Dog assigned;
	assigned = original;

	std::cout << "\n----- Before modification -----\n";
	std::cout << "Original: " << original.getIdea(0) << std::endl;
	std::cout << "Copy:     " << copy.getIdea(0) << std::endl;
	std::cout << "Assigned: " << assigned.getIdea(0) << std::endl;

	// Modify original
	original.setIdea(0, "I CHANGED MY MIND");

	std::cout << "\n----- After modification -----\n";
	std::cout << "Original: " << original.getIdea(0) << std::endl;
	std::cout << "Copy:     " << copy.getIdea(0) << std::endl;
	std::cout << "Assigned: " << assigned.getIdea(0) << std::endl;

	std::cout << "\nIf deep copy is correct:\n";
	std::cout << "Copy and Assigned MUST stay unchanged!\n";
}

static void	test_scope(void)
{
	std::cout << "\n========== SCOPE TEST ==========\n";

	{
		Dog dog;
		Cat cat;

		std::cout << "Leaving scope...\n";
	}

	std::cout << "All destructors should be called above\n";
}

int	main(void)
{
	test_basic();
	test_array();
	test_deep_copy();
	test_scope();
	return (0);
}