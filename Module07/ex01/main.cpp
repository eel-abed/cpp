#include <iostream>
#include <string>
#include "iter.hpp"

static void printInt(const int &value)
{
	std::cout << value << " ";
}

static void incrementInt(int &value)
{
	++value;
}

template <typename T>
void printValue(const T &value)
{
	std::cout << value << " ";
}

int main()
{
	int numbers[] = {1, 2, 3, 4, 5};
	const std::size_t numCount = sizeof(numbers) / sizeof(numbers[0]);

	std::cout << "Original int: ";
	iter(numbers, numCount, printInt);
	std::cout << "\n";

	iter(numbers, numCount, incrementInt);

	std::cout << "Incremented int: ";
	iter(numbers, numCount, printValue<int>);
	std::cout << "\n";

	const std::string words[] = {"allo", "c'est", "moi"};
	const std::size_t wordCount = sizeof(words) / sizeof(words[0]);

	std::cout << "strings: ";
	iter(words, wordCount, printValue<std::string>);
	std::cout << "\n";

	return 0;
}
