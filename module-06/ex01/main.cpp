#include <iostream>
#include "./Serializer.hpp"

int main()
{
	Data	data;

	data.id = 42;
	data.name = "Rub";

	Data*	original = &data;

	// Serialize
	uintptr_t	raw = Serializer::serialize(original);

	// Deserialize
	Data*	restored = Serializer::deserialize(raw);

	std::cout << "Original pointer: " << original << std::endl;
	std::cout << "Restored pointer: " << restored << std::endl;

	if (original == restored)
		std::cout << "Success: pointers are equal!" << std::endl;
	else
		std::cout << "Error: pointers differ!" << std::endl;

	return (0);
}