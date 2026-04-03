#include <iostream>
#include "./Animal.hpp"
#include "./Dog.hpp"
#include "./Cat.hpp"
#include "./WrongAnimal.hpp"
#include "./WrongCat.hpp"

static void	test_normal_animals(void)
{
	std::cout << "========== NORMAL ANIMALS ==========\n";

	const Animal	*meta = new Animal();
	const Animal	*dog = new Dog();
	const Animal	*cat = new Cat();

	std::cout << "\n----- Types -----\n";
	std::cout << "meta type: " << meta->getType() << std::endl;
	std::cout << "dog type: " << dog->getType() << std::endl;
	std::cout << "cat type: " << cat->getType() << std::endl;

	std::cout << "\n----- Sounds through Animal* -----\n";
	meta->makeSound();
	dog->makeSound();
	cat->makeSound();

	std::cout << "\n----- Deleting through Animal* -----\n";
	delete meta;
	delete dog;
	delete cat;
}

static void	test_normal_stack_objects(void)
{
	std::cout << "\n========== STACK OBJECTS ==========\n";

	Animal	meta;
	Dog		dog;
	Cat		cat;

	std::cout << "\n----- Types -----\n";
	std::cout << "meta type: " << meta.getType() << std::endl;
	std::cout << "dog type: " << dog.getType() << std::endl;
	std::cout << "cat type: " << cat.getType() << std::endl;

	std::cout << "\n----- Direct sounds -----\n";
	meta.makeSound();
	dog.makeSound();
	cat.makeSound();
}

static void	test_normal_copy_and_assign(void)
{
	std::cout << "\n========== COPY AND ASSIGN ==========\n";

	Dog	dog1;
	Dog	dog2(dog1);
	Dog	dog3;

	std::cout << "\n----- Dog copy constructor -----\n";
	std::cout << "dog1 type: " << dog1.getType() << std::endl;
	std::cout << "dog2 type: " << dog2.getType() << std::endl;

	std::cout << "\n----- Dog assignment operator -----\n";
	dog3 = dog1;
	std::cout << "dog3 type: " << dog3.getType() << std::endl;

	Cat	cat1;
	Cat	cat2(cat1);
	Cat	cat3;

	std::cout << "\n----- Cat copy constructor -----\n";
	std::cout << "cat1 type: " << cat1.getType() << std::endl;
	std::cout << "cat2 type: " << cat2.getType() << std::endl;

	std::cout << "\n----- Cat assignment operator -----\n";
	cat3 = cat1;
	std::cout << "cat3 type: " << cat3.getType() << std::endl;
}

static void	test_wrong_animals(void)
{
	std::cout << "\n========== WRONG ANIMALS ==========\n";

	const WrongAnimal	*meta = new WrongAnimal();
	const WrongAnimal	*cat = new WrongCat();

	std::cout << "\n----- Types -----\n";
	std::cout << "meta type: " << meta->getType() << std::endl;
	std::cout << "cat type: " << cat->getType() << std::endl;

	std::cout << "\n----- Sounds through WrongAnimal* -----\n";
	meta->makeSound();
	cat->makeSound();

	std::cout << "\n----- Direct WrongCat object -----\n";
	WrongCat	direct_cat;
	direct_cat.makeSound();

	std::cout << "\n----- Deleting wrong objects -----\n";
	delete meta;
	delete cat;
}

static void	test_wrong_copy_and_assign(void)
{
	std::cout << "\n========== WRONG COPY AND ASSIGN ==========\n";

	WrongCat	cat1;
	WrongCat	cat2(cat1);
	WrongCat	cat3;

	std::cout << "\n----- WrongCat copy constructor -----\n";
	std::cout << "cat1 type: " << cat1.getType() << std::endl;
	std::cout << "cat2 type: " << cat2.getType() << std::endl;

	std::cout << "\n----- WrongCat assignment operator -----\n";
	cat3 = cat1;
	std::cout << "cat3 type: " << cat3.getType() << std::endl;
}

int	main(void)
{
	test_normal_animals();
	test_normal_stack_objects();
	test_normal_copy_and_assign();
	test_wrong_animals();
	test_wrong_copy_and_assign();
	return (0);
}