#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    if (N <= 0)
        return nullptr;

    Zombie *z = new Zombie [N];

    for (int i = 0; i < N; i++)
    {
        std::ostringstream oss;
        oss << name << "_" << i + 1;
        z[i].setName(oss.str());
    }

    return z;
}