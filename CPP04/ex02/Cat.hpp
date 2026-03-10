#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
    public:
        Cat();
        ~Cat(void);
        Cat(const Cat &tocopy);
        Cat& operator=(const Cat& src);
        void makeSound() const;

    private:
        Brain *CatBrain;

    protected:


        
};

#endif