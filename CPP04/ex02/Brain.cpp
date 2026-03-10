#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &tocopy) {
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = tocopy.ideas[i];
}

Brain& Brain::operator=(const Brain &src) {
    std::cout << "Brain copy operator called" << std::endl;
    if (this != &src)
        for (int i = 0; i < 100; i++)
            this->ideas[i] = src.ideas[i];
    return (*this);
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}
