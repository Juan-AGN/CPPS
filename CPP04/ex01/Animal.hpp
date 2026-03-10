#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal {
    public:
        Animal();
        virtual ~Animal(void);
        virtual void makeSound() const;
        std::string getType() const;
        Animal& operator=(const Animal& src);
        Animal(const Animal& src);

    protected:
        Animal(std::string type);

        std::string type;
        
};

#endif