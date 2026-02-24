#include "Span.hpp"
#include <iostream>

int main()
{
	// Basic test from subject
	std::cout << "+++ teste base +++" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << std::endl;

	// Test with large number using range iterators
	std::cout << "--- TEST 10K NOMBRE ---" << std::endl;
	std::vector<int> numbers;
	for (int i = 0; i < 10000; ++i)
	{
		numbers.push_back(i);
	}

	Span sp2(10000);
	sp2.addNumbers(numbers.begin(), numbers.end());

	std::cout << "Added " << sp2.getSize() << " numbers using iterators" << std::endl;
	std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
	std::cout << std::endl;

	std::cout << "=== Exception Tests ===" << std::endl;
	try
	{
		Span sp3(5);
		sp3.shortestSpan(); // Should throw (not enough numbers)
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Span sp4(2);
		sp4.addNumber(1);
		sp4.addNumber(2);
		sp4.addNumber(3); // Should throw (span full)
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
