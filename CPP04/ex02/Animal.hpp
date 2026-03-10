#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal {
    public:
        Animal();
        virtual ~Animal(void);
        virtual void makeSound() const = 0;
        std::string getType() const;
        virtual Animal& operator=(const Animal& src);
        Animal(const Animal& src);

    protected:
        Animal(std::string type);

        std::string type;

        
};

#endif