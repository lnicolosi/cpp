#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() 
{
    std::cout << "\n===== TEST 1: CONSTRUCTION =====\n" << std::endl;
    FragTrap frag("Boomer");
    frag.printStats();

    std::cout << "\n===== TEST 2: BASIC ACTIONS =====\n" << std::endl;
    frag.attack("Target Dummy");
    frag.beRepaired(5);
    frag.printStats();

    std::cout << "\n===== TEST 3: HIGH FIVE FEATURE =====\n" << std::endl;
    frag.highFivesGuys();

    std::cout << "\n===== TEST 4: DAMAGE TO DEATH =====\n" << std::endl;
    frag.takeDamage(40);
    frag.takeDamage(40);
    frag.takeDamage(30); // FragTrap now dead
    frag.printStats();

    std::cout << "\n===== TEST 5: TRY ACTIONS WHILE DEAD =====\n" << std::endl;
    frag.attack("Ghost");
    frag.beRepaired(10);
    frag.highFivesGuys(); // This should still work

    std::cout << "\n===== TEST 6: ENERGY DEPLETION =====\n" << std::endl;
    FragTrap tireur("Laser");
    for (int i = 0; i < 100; ++i)
        tireur.attack("Practice Dummy"); // Should run out of energy around 100
    tireur.attack("One more time");
    tireur.printStats();

    std::cout << "\n===== END OF SCOPE: DESTRUCTORS =====\n" << std::endl;
    return 0;
}
