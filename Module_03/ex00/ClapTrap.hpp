#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
    private:
        std::string _name;
        int         _hitPoints = 10;
        int         _energyPoints = 10;
        int         _attackDamage = 0;

    public:
        ClapTrap();
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap& other);
        ~ClapTrap();

};





#endif
