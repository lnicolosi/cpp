#include "Zombie.hpp"

int main()
{
    Zombie *z = newZombie("Dynamique");
    z->announce();

    randomChump("Stack");

    delete z;

    return 0;
}