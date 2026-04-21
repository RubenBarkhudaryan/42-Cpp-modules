#include <ctime>
#include <cstdlib>
#include <iostream>
#include "./A.hpp"
#include "./B.hpp"
#include "./C.hpp"
#include "./Base.hpp"

Base	*generate(void)
{
	int	gen_id;

	gen_id = (std::rand() % 3);

	if (gen_id == 0)
		return (new A());
	if (gen_id == 1)
		return (new B());
	if (gen_id == 2)
		return (new C());

	return (NULL);
}

void	identify(Base *ptr)
{

	A*	a_obj = dynamic_cast<A*>(ptr);
	if (a_obj != NULL)
	{
		std::cout << "Instance of A class" << std::endl;
		return ;
	}


	B*	b_obj = dynamic_cast<B*>(ptr);
	if (b_obj != NULL)
	{
		std::cout << "Instance of B class" << std::endl;
		return ;
	}


	C*	c_obj = dynamic_cast<C*>(ptr);
	if (c_obj != NULL)
	{
		std::cout << "Instance of C class" << std::endl;
		return ;
	}

	std::cout << "Unknown type" << std::endl;
}

void	identify(Base &ref)
{
	try
	{
		(void)dynamic_cast<A&>(ref);
		std::cout << "Instance of A class" << std::endl;
		return ;
	}
	catch(...)
	{
	}

	try
	{
		(void)dynamic_cast<B&>(ref);
		std::cout << "Instance of B class" << std::endl;
		return ;
	}
	catch(...)
	{
	}

	try
	{
		(void)dynamic_cast<C&>(ref);
		std::cout << "Instance of C class" << std::endl;
		return ;
	}
	catch(...)
	{
	}

	std::cout << "Unknown type" << std::endl;
}

int	main()
{
	std::srand(std::time(NULL));

	Base	*ptr1 = generate();
	Base	*ptr2 = generate();
	Base	*ptr3 = generate();
	Base	*ptr4 = generate();

	identify(ptr1);
	identify(ptr2);
	identify(*ptr3);
	identify(*ptr4);
	identify((Base *)NULL);

	delete ptr1;
	delete ptr2;
	delete ptr3;
	delete ptr4;

	return (0);
}