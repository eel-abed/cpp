#include "Intern.hpp"
#include "AForm.hpp"

int main() {
	std::cout << "test1 intern create valid forms" << std::endl;
	try {
		Intern someIntern;
		AForm* rrf;
		
		rrf = someIntern.makeForm("robotomy request", "C67P0");
		delete rrf;
		
		AForm* scf = someIntern.makeForm("shrubbery creation", "MAISON");
		delete scf;
		
		AForm* ppf = someIntern.makeForm("presidential pardon", "JEAN CLAUDE VIANDE ARM");
		delete ppf;
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << "\n+++++++ intern create invalid ++++++" << std::endl;
	try {
		Intern intern2;
		AForm* invalid = intern2.makeForm("invalid form", "target");
		delete invalid;
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << "\n===== TEST 3 MAL ECRIS+====" << std::endl;
	try {
		Intern intern3;
		AForm* form = intern3.makeForm("Robotomy Request", "target");
		delete form;
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	return 0;
}
