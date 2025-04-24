#include "Zombie.hpp"

int main()
{
    int hordSize;

    do
    {
        std::cout << "Enter the number of Zombie in the Hord: ";
        std::cin >> hordSize;
    } while (hordSize <= 0);

    Zombie *z = zombieHorde(hordSize, "Eliot");
    for(int i = 0; i < hordSize; i++)
    {
        std::cout << i + 1 << ": " ;
        z[i].announce();
    }

    delete[] z;

    z = nullptr; 
    return 0;
}