#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "Constructeur";
    printThis();
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    _type = other._type;
    std::cout << "Constructeur de copie";
    printThis();
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    if (this != &other)
    {
        _type = other._type;
    }
    std::cout << "Opérateur d'affectation";
    printThis();
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Destructeur"; 
    printThis();
}

//------------------------------------------------------

void WrongAnimal::printThis()
{
    std::cout << " WrongAnimal (parent) " << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "AaaAAAAaaaAAA !!! " << std::endl;
}

const std::string& WrongAnimal::getType() const
{
    return _type;
}

