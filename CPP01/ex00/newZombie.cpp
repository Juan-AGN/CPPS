#include "Zombie.hpp"

Zombie *newZombie( std::string name ) {
    Zombie *zombieToRet = new Zombie(name);

    return (zombieToRet);
};
