#include <iostream>

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongDog.hpp"
#include "WrongCat.hpp"

int main()
{
	const int size = 10;
	Animal *animals[size];

	for (int i = 0; i < size; i ++)
	{
		if (i % 2 == 0)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}

	for (int i = 0; i < size; i += 1)
		delete animals[i];


	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;

	Dog* y = new Dog();
	Cat* z = new Cat();
	const Dog* a = new Dog(*y);
	const Cat* b = new Cat(*z);
	delete y;
	delete z;
	delete a;
	delete b;
}