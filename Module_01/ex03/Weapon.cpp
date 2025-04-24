#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

//default constructor
Weapon::Weapon()
{

}
//constructor
Weapon::Weapon(std::string type)
{
    _type = type;
}

Weapon::~Weapon()
{

}


void Weapon::setType(const std::string& type)
{
    _type = type;
}

const std::string& Weapon::getType() const
{
    return _type;
}