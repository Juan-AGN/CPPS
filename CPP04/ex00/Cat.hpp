#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"

class Cat : public Animal {
    public:
        Cat();
        ~Cat(void);
        void makeSound() const;
        Cat(const Cat &tocopy);
        Cat& operator=(const Cat& src);

    private:

    protected:

        
};

#endif