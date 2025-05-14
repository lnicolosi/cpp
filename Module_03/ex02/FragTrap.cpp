#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "Constructeur par default FragTrap (enfant2)" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "Constructeur FragTrap (enfant2)" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "Constructeur de copie FragTrap (enfant2)" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    std::cout << "Operateur d'affectation FragTrap (enfant2)" << std::endl;
    return (*this); 
}

FragTrap::~FragTrap()
{
    std::cout << "Destructeur FragTrap (enfant2)" << std::endl;
}

//-------------------------------------------------------------------------

void FragTrap::highFivesGuys(void)
{
    std::cout << "Hey bro! You did a good job. HIGH FIVE !!!" << std::endl;
}