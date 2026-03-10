#include "Animal.hpp"

Animal::~Animal(void)
{
    std::cout << "Animal estructor called" << std::endl; 
}

Animal::Animal() {
    std::cout << "Animal constructor called" << std::endl; 
}

Animal::Animal(std::string totype) {
    std::cout << "Animal string constructor called" << std::endl;
    this->type = totype;
}

Animal::Animal(const Animal& src) {
    std::cout << "Animal copy constructor called" << std::endl;
    this->type = src.type;
}

void Animal::makeSound() const {
    std::cout << "What am i?" << std::endl;
}

std::string Animal::getType() const {
    return (this->type);
}

Animal& Animal::operator=(const Animal& src) {
    std::cout << "Animal assign coperator called" << std::endl;
    if (this != &src)
        this->type = src.type;
    return (*this);
}
