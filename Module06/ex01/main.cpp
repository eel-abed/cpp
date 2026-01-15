#include <iostream>
#include "Serializer.hpp"

static void printData(const std::string &label, Data *ptr)
{
	if (!ptr)
	{
		std::cout << label << " is NULL" << std::endl;
		return;
	}
	std::cout << label << " address: " << ptr
			  << " | value: " << ptr->value << std::endl;
}

int main(void)
{
	Data original;
	original.value = 67;

	uintptr_t raw = Serializer::serialize(&original);
	Data *restored = Serializer::deserialize(raw);

	printData("Original", &original);
	printData("Restored", restored);

	return 0;
}
