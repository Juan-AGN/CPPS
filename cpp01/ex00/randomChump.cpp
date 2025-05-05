#include "Zombie.hpp"

void randomChump( std::string name )
{
    Zombie  zombieRandom(name);

    zombieRandom.announce();
}