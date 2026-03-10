#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iomanip>
# include <iostream>
# include <string>
# include <stdlib.h>


class Zombie {
    public:
        void announce( void ); 

        void setName(std::string zomName);

        Zombie(std::string zomName);

        ~Zombie(void);

        Zombie(void);

        Zombie& operator=(const Zombie& other);

        Zombie(const Zombie &toCopy);

    private:
        std::string name;
        
};

#endif