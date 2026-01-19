#include <iostream>
#include <cstdlib>
#include <ctime>
#include "functions.hpp"

int main(void)
{
	srand(static_cast<unsigned int>(time(NULL)));

	for (int i = 0; i < 5; i++)
	{
		Base *obj = generate();

		std::cout << "Type (pointer): ";
		identify(obj);

		std::cout << "Type (reference): ";
		identify(*obj);

		delete obj;
	}

	return 0;
}

