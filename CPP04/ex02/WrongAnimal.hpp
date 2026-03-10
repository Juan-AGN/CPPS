#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal {
    public:
        WrongAnimal();
        WrongAnimal(std::string type);
        ~WrongAnimal(void);
        WrongAnimal(const WrongAnimal& src);
        void makeSound() const;
        std::string getType() const;
        WrongAnimal& operator=(const WrongAnimal& src);

    protected:
        std::string type;
        
};

#endif