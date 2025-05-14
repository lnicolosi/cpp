#include "ClapTrap.hpp"

int main() 
{
    std::cout << "\n===== TEST 1: NORMAL ACTIONS =====\n" << std::endl;
    ClapTrap bob("Bob");
    bob.printStats();
    bob.attack("Target Dummy");
    bob.beRepaired(5);
    bob.printStats();

    std::cout << "\n===== TEST 2: NO ENERGY =====\n" << std::endl;
    ClapTrap tina("Tina");
    for (int i = 0; i < 10; ++i)
        tina.attack("Training Bot");
    tina.printStats();
    tina.attack("Another Bot");  // devrait échouer

    std::cout << "\n===== TEST 3: DEATH =====\n" << std::endl;
    ClapTrap mark("Mark");
    mark.takeDamage(4);
    mark.takeDamage(3);
    mark.takeDamage(3);  // Mark à 0 HP ici
    mark.attack("Whoever");     // devrait échouer
    mark.beRepaired(5);         // devrait échouer
    mark.printStats();

    std::cout << "\n===== TEST 4: ALL ACTIONS ONCE =====\n" << std::endl;
    ClapTrap jack("Jack");
    jack.printStats();
    jack.attack("Enemy Bot");
    jack.takeDamage(6);
    jack.beRepaired(4);
    jack.printStats();
    
    return 0;
}
