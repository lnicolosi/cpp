#include "animal.hpp"

Animal::Animal()
{
    std::cout << "Constructeur";
    printThis();
}

Animal::Animal(const Animal& other)
{
    _type = other._type;
    std::cout << "Constructeur de copie";
    printThis();
}

Animal& Animal::operator=(const Animal& other)
{
    if (this != &other)
    {
        _type = other._type;
    }
    std::cout << "Opérateur d'affectation";
    printThis();
    return *this;
}

Animal::~Animal()
{
    std::cout << "Destructeur"; 
    printThis();
}

//------------------------------------------------------

void Animal::printThis()
{
    std::cout << " Animal (parent) " << std::endl;
}


const std::string& Animal::getType() const
{
    return _type;
}

