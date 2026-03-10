#include "Cat.hpp"

Cat::~Cat(void)
{
    delete this->CatBrain;
    std::cout << "Cat destructor called" << std::endl; 
}

Cat::Cat() : Animal("Cat") {
    std::cout << "Cat constructor called" << std::endl;
    this->type = "cat";
    this->CatBrain = new Brain;
    for (int x = 0; x < 100; x ++)
        this->CatBrain->ideas[x] = "Cat idea";
}

Cat::Cat(const Cat &tocopy) {
    std::cout << "Cat copy constructor called" << std::endl;
    this->type = tocopy.type; 
    this->CatBrain = new Brain(*(tocopy.CatBrain));
}

Cat& Cat::operator=(const Cat& src) {
    std::cout << "Cat assign operator called" << std::endl;
    if (this != &src)
    {
        this->type = src.type;
        delete this->CatBrain;
        this->CatBrain = new Brain(*(src.CatBrain));
    }
    return (*this);
}

void Cat::makeSound() const {
    std::cout << "Meow" << std::endl;
}
