#include "Dog.hpp"

Dog::~Dog(void)
{
    std::cout << "Dog destructor called" << std::endl; 
}

Dog::Dog() : Animal("Dog") {
    std::cout << "Dog constructor called" << std::endl; 
}

Dog::Dog(const Dog &tocopy) {
    std::cout << "Dog copy constructor called" << std::endl;
    this->type = tocopy.type; 
}

Dog& Dog::operator=(const Dog& src) {
    std::cout << "Dog assign operator called" << std::endl;
    if (this != &src)
        this->type = src.type;
    return (*this);
}

void Dog::makeSound() const {
    std::cout << "Bark" << std::endl;
}
