#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "Constructeur par default ScavTrap (enfant)" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "Constructeur ScavTrap (enfant)" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "Constructeur de copie ScavTrap (enfant)" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    std::cout << "Operateur d'affectation ScavTrap (enfant)" << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "Destructeur ScavTrap (enfant)" << std::endl;
}

//--------------------------------------------------------------------------

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (hasEnergy() && isAlive())
    {
        _energyPoints--;
        std::cout << ORANGE << " >> SCAVTRAP ATTACK <<" << RESET << std::endl;
        std::cout << "ScavTrap " << _name << " attacks " << target 
                << ", causing " << _attackDamage << " points of damage!" 
                << std::endl;
    }
    else
    {
        if (!isAlive())
        {
            std::cout << _name << " can't attack, he is dead..." << std::endl;
            return ;
        }
        if (!hasEnergy())
            std::cout << _name << " can't attack, he has no energy..." << std::endl;
    }
  
}