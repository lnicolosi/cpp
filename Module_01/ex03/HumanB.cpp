#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"



HumanB::HumanB(std::string name) : _name (name), _weapon(nullptr)
{

}

HumanB::~HumanB(void)
{

}

void HumanB::attack()
{
    if (_weapon)
        std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
    else
        std::cout << _name << " has no weapon" << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
    _weapon = &weapon;
}