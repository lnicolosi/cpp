#include "dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Constructeur ";
    _type = "Dog";
    printThis();
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Constructeur de copie ";
    printThis();
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        Animal::operator=(other);
    }
    std::cout << "Operateur d'affectation ";
    printThis();
    return *this;
}

Dog::~Dog()
{
    std::cout << "Destructeur ";
    printThis();
}

//---------------------------------------------------------------------

void Dog::printThis()
{
    std::cout << _type << " (enfant) " << std::endl;
    
}


void Dog::makeSound() const
{
    std::cout << _type << " WOUF WOUF !!" << std::endl;
}



