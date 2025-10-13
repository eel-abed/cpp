#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound();
j->makeSound();
meta->makeSound();

//Test Wronganimals
std::cout << "\n++++++++WRONGANIMAL TEST++++++++" << std::endl;
const WrongAnimal* wrongAnimal = new WrongAnimal();
const WrongAnimal* wrongCatPtr = new WrongCat();
std::cout << "WrongAnimal type: " << wrongAnimal->getType() << std::endl;
std::cout << "WrongCat type: " << wrongCatPtr->getType() << std::endl;
wrongAnimal->makeSound();
wrongCatPtr->makeSound();

delete meta;
delete j;
delete i;
delete wrongAnimal;
delete wrongCatPtr;
return 0;
}
