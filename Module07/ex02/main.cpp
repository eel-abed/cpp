#include <iostream>
#include "Array.hpp"

int main()
{
	// Test 1: Default constructor (empty array)
	std::cout << "Test 1: Default constructor" << std::endl;
	Array<int> emptyArray;
	std::cout << "Size: " << emptyArray.size() << std::endl;
	std::cout << std::endl;

	// Test 2: Constructor with unsigned int
	std::cout << "Test 2: Constructor with size 5" << std::endl;
	Array<int> intArray(5);
	std::cout << "Size: " << intArray.size() << std::endl;
	std::cout << "Elements (default initialized): ";
	for (unsigned int i = 0; i < intArray.size(); ++i)
	{
		std::cout << intArray[i] << " ";
	}
	std::cout << std::endl
			  << std::endl;

	// Test 3: Set elements
	std::cout << "Test 3: Setting elements" << std::endl;
	for (unsigned int i = 0; i < intArray.size(); ++i)
	{
		intArray[i] = i * 10;
	}
	std::cout << "Elements: ";
	for (unsigned int i = 0; i < intArray.size(); ++i)
	{
		std::cout << intArray[i] << " ";
	}
	std::cout << std::endl
			  << std::endl;

	// Test 4: Copy constructor (deep copy)
	std::cout << "Test 4: Copy constructor" << std::endl;
	Array<int> copiedArray(intArray);
	std::cout << "Original: ";
	for (unsigned int i = 0; i < intArray.size(); ++i)
	{
		std::cout << intArray[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Copy: ";
	for (unsigned int i = 0; i < copiedArray.size(); ++i)
	{
		std::cout << copiedArray[i] << " ";
	}
	std::cout << std::endl
			  << std::endl;

	// Test 5: Modify copy and check independence
	std::cout << "Test 5: Modify copy (independence test)" << std::endl;
	copiedArray[0] = 999;
	std::cout << "Original[0]: " << intArray[0] << std::endl;
	std::cout << "Copy[0]: " << copiedArray[0] << std::endl;
	std::cout << std::endl;

	// Test 6: Assignment operator (deep copy)
	std::cout << "Test 6: Assignment operator" << std::endl;
	Array<int> assignedArray(3);
	assignedArray[0] = 100;
	assignedArray[1] = 200;
	assignedArray[2] = 300;

	Array<int> anotherArray = assignedArray;
	std::cout << "Assigned array: ";
	for (unsigned int i = 0; i < anotherArray.size(); ++i)
	{
		std::cout << anotherArray[i] << " ";
	}
	std::cout << std::endl;

	anotherArray[1] = 777;
	std::cout << "Original[1]: " << assignedArray[1] << std::endl;
	std::cout << "Assigned[1]: " << anotherArray[1] << std::endl;
	std::cout << std::endl;

	// Test 7: Bounds checking
	std::cout << "Test 7: Bounds checking (trying to access out of bounds)" << std::endl;
	try
	{
		intArray[100];
		std::cout << "ERROR: Should have thrown exception!" << std::endl;
	}
	catch (const std::out_of_range &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test 8: Array of strings
	std::cout << "Test 8: Array of strings" << std::endl;
	Array<std::string> stringArray(3);
	stringArray[0] = "Hello";
	stringArray[1] = "World";
	stringArray[2] = "!";
	std::cout << "Strings: ";
	for (unsigned int i = 0; i < stringArray.size(); ++i)
	{
		std::cout << stringArray[i] << " ";
	}
	std::cout << std::endl
			  << std::endl;

	// Test 9: Const array and const access
	std::cout << "Test 9: Const array access" << std::endl;
	const Array<int> constArray(intArray);
	std::cout << "Const array element [0]: " << constArray[0] << std::endl;
	std::cout << std::endl;

	return 0;
}
