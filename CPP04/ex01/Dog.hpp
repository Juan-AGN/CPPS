#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal{
    public:
        Dog();
        ~Dog(void);
        void makeSound() const;
        Dog(const Dog &tocopy);
        Dog& operator=(const Dog& src);

    private:
        Brain *DogBrain;

    protected:

        
};

#endif