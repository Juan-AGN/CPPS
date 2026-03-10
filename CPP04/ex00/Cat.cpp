#include "Cat.hpp"

Cat::~Cat(void)
{
    std::cout << "Cat destructor called" << std::endl; 
}

Cat::Cat() : Animal("Cat") {
    std::cout << "Cat constructor called" << std::endl; 
}

Cat::Cat(const Cat &tocopy) {
    std::cout << "Cat copy constructor called" << std::endl;
    this->type = tocopy.type; 
}

Cat& Cat::operator=(const Cat& src) {
    std::cout << "Cat assign operator called" << std::endl;
    if (this != &src)
        this->type = src.type;
    return (*this);
}

void Cat::makeSound() const {
    std::cout << "Meow" << std::endl;
}
