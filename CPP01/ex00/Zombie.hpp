#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iomanip>
# include <iostream>
# include <string>
# include <stdlib.h>


class Zombie {
    public:
        void announce( void ); 

        Zombie(std::string zomName);

        ~Zombie(void);

    private:
        std::string name;
        
};

#endif