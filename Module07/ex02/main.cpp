#include <iostream>
#include "Array.hpp"

int main()
{
	std::cout << "+++basic test+++" << std::endl;
	Array<int> arr(5);
	std::cout << "Size: " << arr.size() << std::endl;
	
	for (unsigned int i = 0; i < arr.size(); ++i)
	{
		arr[i] = i * 10;
	}
	
	std::cout << "Elements: ";
	for (unsigned int i = 0; i < arr.size(); ++i)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "\n\n";

	std::cout << "=== recopie ===" << std::endl;
	Array<int> copy(arr);
	copy[0] = 999;
	
	std::cout << "Original[0]: " << arr[0] << std::endl;
	std::cout << "Copy[0]: " << copy[0] << std::endl;

	
	std::cout << "*** exception ***" << std::endl;
	try
	{
		arr[100];
		std::cout << "ERROR: WHY IS THIS WORKING?!?!?!" << std::endl;
	}
	catch (const std::out_of_range &e)
	{
		std::cout << "exception: " << e.what() << std::endl;
	}

	return 0;
}
