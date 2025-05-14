#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :
    _name("Default"),
    _hitPoints(10),
    _energyPoints(10),
    _attackDamage(0)
{
    std::cout << "Constructeur par default ClapTrap" << std::endl; 
}

ClapTrap::ClapTrap(const std::string& name) :
    _name(name),
    _hitPoints(10),
    _energyPoints(10),
    _attackDamage(0)
{
    std::cout << "Constructeur ClapTrap" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) :
    _name(other._name),
    _hitPoints(other._hitPoints),
    _energyPoints(other._energyPoints),
    _attackDamage(other._attackDamage)
{
    std::cout << "Constructeur de copie ClapTrap" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    std::cout << "Operateur d'affectation ClapTrap" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructeur ClapTrap" << std::endl;
}

//-------------------------------------------------------

bool ClapTrap::hasEnergy()
{
    if (_energyPoints > 0)
        return true;
    else
        return false;
}

bool ClapTrap::isAlive()
{
    if (_hitPoints > 0)
        return true;
    else
        return false;
}

void ClapTrap::printStats()
{
    std::cout << "ClapTrap " << _name << " STATS : " << std::endl;
    std::cout << "Hit points (health)   : " << _hitPoints << std::endl;
    std::cout << "Energy                : " << _energyPoints << std::endl;
    std::cout << "Attack damage         : " << _attackDamage << std::endl << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (hasEnergy() && isAlive())
    {
        _energyPoints--;
        std::cout << YELLOW << " >> ATTACK <<" << RESET << std::endl;
        std::cout << "ClapTrap " << _name << " attacks " << target 
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

void ClapTrap::takeDamage(unsigned int amount)
{
    if (isAlive())
    {
        if (amount >= static_cast<unsigned int>(_hitPoints))
            _hitPoints = 0;
        else
            _hitPoints -= amount;
        std::cout << RED << " >> TAKE DAMAGE <<" << RESET << std::endl;
        std::cout << _name << " takes " << amount << " damages!" 
                  << std::endl;
    }
    else
    {
        std::cout << _name << " is already dead..." << std::endl;
    }
    if (!isAlive())
        std::cout << _name << " is now dead..." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hasEnergy() && isAlive())
    {
        _energyPoints--;
        _hitPoints += amount;
        std::cout << GREEN << " >> REPAIR <<" << RESET << std::endl;
        std::cout << _name << " repairs " << amount << " hit points!"
                  << std::endl;
    }
    else
    {
        if (!isAlive())
        {
            std::cout << _name << " can't repair himself, he is dead..." << std::endl;
            return ;
        }
        if (!hasEnergy())
            std::cout << _name << " can't repair himself, he has no energy..." << std::endl;
    }
}
