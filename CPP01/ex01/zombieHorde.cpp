#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
    Zombie *zombieToRet = new Zombie[N];

    for (int nZom = 0; nZom < N; nZom ++)
        zombieToRet[nZom].setName(name);
    return (zombieToRet);
};
