#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
	std::cout << "=== Test 1: Create form invalide ===" << std::endl;
	try {
		Form invalid("Invalid Form", 0, 50);
		std::cout << invalid << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << "Exception : " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 2: bureau signe ===" << std::endl;
	try {
		Bureaucrat ongle("Ongle", 30);
		Form formC("Permission parking", 50, 25);
		std::cout << formC << std::endl;
		ongle.signForm(formC);
		std::cout << formC << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << "Exception : " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 3: Bureaucrat sign grade too low ===" << std::endl;
	try {
		Bureaucrat orteille("Orteille", 100);
		Form formD("Top Secret FBI", 50, 25);
		std::cout << orteille << std::endl;
		std::cout << formD << std::endl;
		orteille.signForm(formD);
		std::cout << formD << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << "Exception : " << e.what() << std::endl;
	}

	return 0;
}
