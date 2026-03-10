#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
    public:
        ~WrongCat();
        WrongCat();
        WrongCat(const WrongCat &tocopy);
        WrongCat& operator=(const WrongCat& src);

    private:

    protected:

        
};

#endif