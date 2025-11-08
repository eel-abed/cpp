#include "Bureaucrat.hpp"
#include <iostream>

int main() {
	std::cout << "=== Test 1: Grade Increment ===" << std::endl;
	try {
		Bureaucrat bob("Bob", 2);
		std::cout << bob << std::endl;
		bob.incrementGrade();
		std::cout << bob << std::endl;
		bob.incrementGrade();
	}
	catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 2: TOOLOW ===" << std::endl;
	try {
		Bureaucrat invalid("Invalid", 151);
		std::cout << invalid << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 3: TOOFAR===" << std::endl;
	try {
		Bureaucrat eve("Eve", 150);
		std::cout << eve << std::endl;
		eve.decrementGrade();
	}
	catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
