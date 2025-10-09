#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	delete j;
	delete i;
	//test change copied animal first idea
	Dog dog1;
	dog1.getBrain()->setIdea(0, "I love bones!");
	Dog dog2 = dog1;
	dog2.getBrain()->setIdea(0, "I love cats!");
	std::cout << "Dog1 idea: " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog2 idea: " << dog2.getBrain()->getIdea(0) << std::endl;
	//test array with vitual
	std::cout << "D-------8"<< std::endl;
	Animal* animals[4];
	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Dog();
	animals[3] = new Cat();
	for (int k = 0; k < 4; k++) {
		animals[k]->makeSound();
		delete animals[k];
	}

	return 0;
}
