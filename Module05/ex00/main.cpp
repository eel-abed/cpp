#include "Bureaucrat.hpp"
#include <iostream>

int main() {
	std::cout << "=== Test 1: Grade Increment ===" << std::endl;
	try {
		Bureaucrat zgeg("zgeg", 2);
		std::cout << zgeg << std::endl;
		zgeg.incrementGrade();
		std::cout << zgeg << std::endl;
		zgeg.incrementGrade();
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 2: TOOLOW ===" << std::endl;
	try {
		Bureaucrat invalid("Invalid", 151);
		std::cout << invalid << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 3: TOOFAR===" << std::endl;
	try {
		Bureaucrat eve("Eve", 150);
		std::cout << eve << std::endl;
		eve.decrementGrade();
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
