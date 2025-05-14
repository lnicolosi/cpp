#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() 
{
    std::cout << "\n===== TEST 1: CONSTRUCTION & STATS =====\n" << std::endl;
    ScavTrap unit("Guardian");
    unit.printStats();

    std::cout << "\n===== TEST 2: ATTACK WITH CUSTOM MESSAGE =====\n" << std::endl;
    unit.attack("Intruder");

    std::cout << "\n===== TEST 3: GUARD GATE MODE =====\n" << std::endl;
    unit.guardGate();

    std::cout << "\n===== TEST 4: TAKE DAMAGE & REPAIR =====\n" << std::endl;
    unit.takeDamage(20);
    unit.beRepaired(10);
    unit.printStats();

    std::cout << "\n===== END OF SCOPE: DESTRUCTION CHAIN =====\n" << std::endl;
    return 0;
}
