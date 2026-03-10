#ifndef WRONGDOG_HPP
# define WRONGDOG_HPP

# include <iostream>
# include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal{
    public:
        ~WrongDog();
        WrongDog();
        WrongDog(const WrongDog &tocopy);
        WrongDog& operator=(const WrongDog& src);

    private:

    protected:

        
};

#endif