#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	std::cout << "=== create shrubery ===" << std::endl;
	try {
		Bureaucrat bob("Bob", 140);
		ShrubberyCreationForm shrub("home");
		
		std::cout << bob << std::endl;
		std::cout << shrub << std::endl;
		
		bob.signForm(shrub);
		bob.executeForm(shrub);
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << "\n---RobotomyRequestForm Success---" << std::endl;
	try {
		Bureaucrat alice("Alice", 40);
		RobotomyRequestForm robot("Bender");
		
		std::cout << alice << std::endl;
		std::cout << robot << std::endl;
		
		alice.signForm(robot);
		alice.executeForm(robot);
		alice.executeForm(robot); 
		alice.executeForm(robot);
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << "\n=-= pardon predisentiel =-=" << std::endl;
	try {
		Bureaucrat president("President", 1);
		PresidentialPardonForm pardon("John Pork");
		
		std::cout << president << std::endl;
		std::cout << pardon << std::endl;
		
		president.signForm(pardon);
		president.executeForm(pardon);
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << "\n+++ FORM NOT SIGNED +++" << std::endl;
	try {
		Bureaucrat john("John", 1);
		ShrubberyCreationForm shrub("garden");
		
		john.executeForm(shrub);
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << "\n___ 2 low to sign ___" << std::endl;
	try {
		Bureaucrat intern("Intern", 150);
		PresidentialPardonForm pardon("Criminal");
		
		intern.signForm(pardon);
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << "\n2 low to exec" << std::endl;
	try {
		Bureaucrat lowGrade("LowGrade", 50);
		Bureaucrat highGrade("HighGrade", 1);
		PresidentialPardonForm pardon("Someone");
		
		highGrade.signForm(pardon);
		lowGrade.executeForm(pardon);
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << "\nbcp forms" << std::endl;
	try {
		Bureaucrat boss("Boss", 1);
		ShrubberyCreationForm shrub1("office");
		ShrubberyCreationForm shrub2("park");
		RobotomyRequestForm robot("Employee");
		PresidentialPardonForm pardon("Tax Evader");
		
		boss.signForm(shrub1);
		boss.signForm(shrub2);
		boss.signForm(robot);
		boss.signForm(pardon);
		
		boss.executeForm(shrub1);
		boss.executeForm(shrub2);
		boss.executeForm(robot);
		boss.executeForm(pardon);
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	return 0;
}
