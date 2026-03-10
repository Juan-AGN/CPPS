#include <iostream>

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongDog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << "\e[1;41m\e[1;36m" << std::endl << std::endl;
	std::cout << "It's midnight and the wrong animals have awaken. " << std::endl;
	std::cout << "                                                 \e[0m" << std::endl << std::endl;

	const WrongAnimal* meta2 = new WrongAnimal();
	const WrongAnimal* j2 = new WrongDog();
	const WrongAnimal* i2 = new WrongCat();

	std::cout << j2->getType() << " " << std::endl;
	std::cout << i2->getType() << " " << std::endl;
	i2->makeSound();
	j2->makeSound();
	meta2->makeSound();

	delete meta2;
	delete j2;
	delete i2;

	return 0;
}