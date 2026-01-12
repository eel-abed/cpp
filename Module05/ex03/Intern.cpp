#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {
	std::cout << "Intern created" << std::endl;
}

Intern::Intern(const Intern& other) {
	(void)other;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	std::cout << "Intern copy assignment operator called" << std::endl;
	return *this;
}

Intern::~Intern() {
	std::cout << "Intern destroyed" << std::endl;
}

AForm* Intern::makeShrubberyCreationForm(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomyRequestForm(const std::string& target) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::makePresidentialPardonForm(const std::string& target) {
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
	struct FormCreator {
		std::string name;
		AForm* (Intern::*creator)(const std::string& target);
	};

	FormCreator forms[] = {
		{"shrubbery creation", &Intern::makeShrubberyCreationForm},
		{"robotomy request", &Intern::makeRobotomyRequestForm},
		{"presidential pardon", &Intern::makePresidentialPardonForm}
	};

	for (int i = 0; i < 3; i++) {
		if (forms[i].name == formName) {
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*(forms[i].creator))(target);
		}
	}

	throw FormNotFoundException();
}

const char* Intern::FormNotFoundException::what() const throw() {
	return "Error: Form name not recognized!";
}
