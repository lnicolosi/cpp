#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define ORANGE  "\033[38;5;208m"


#include <iostream>
#include <string>

class ClapTrap
{
    protected:
        std::string _name;
        int         _hitPoints;        //HEALTH
        int         _energyPoints;     //ENERGY
        int         _attackDamage;      //DAMAGE

    public:
        ClapTrap();
        ClapTrap(const std::string& name);
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap& other);
        ~ClapTrap();

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        bool hasEnergy();
        bool isAlive();

        void printStats();

};





#endif
