#include "Zombie.hpp"

void randomChump(const std::string& name)
{
    Zombie z(name);
    z.announce();
}