#include "Dog.hpp"

Dog::~Dog(void)
{
    delete this->DogBrain;
    std::cout << "Dog destructor called" << std::endl; 
}

Dog::Dog() : Animal("Dog") {
    std::cout << "Dog constructor called" << std::endl; 
    this->type = "Dog";
    this->DogBrain = new Brain;
    for (int x = 0; x < 100; x ++)
        this->DogBrain->ideas[x] = "Dog idea";
}

Dog::Dog(const Dog &tocopy) {
    std::cout << "Dog copy constructor called" << std::endl;
    this->type = tocopy.type; 
    this->DogBrain = new Brain(*(tocopy.DogBrain));
}

Dog& Dog::operator=(const Dog& src) {
    std::cout << "Dog assign operator called" << std::endl;
    if (this != &src)
    {
        this->type = src.type;
        delete this->DogBrain;
        this->DogBrain = new Brain(*(src.DogBrain));
    }
    return (*this);
}

void Dog::makeSound() const {
    std::cout << "Bark" << std::endl;
}
