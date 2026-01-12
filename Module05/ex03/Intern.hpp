#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>

class AForm;

class Intern {
public:
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();

	AForm*	makeForm(const std::string& formName, const std::string& target);

private:
	AForm*	makeShrubberyCreationForm(const std::string& target);
	AForm*	makeRobotomyRequestForm(const std::string& target);
	AForm*	makePresidentialPardonForm(const std::string& target);

	class FormNotFoundException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

#endif
