#include "cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << "Constructeur ";
    _type = "Cat";
    printThis();
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Constructeur de copie ";
    printThis();
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        Animal::operator=(other);
    }
    std::cout << "Opérateur d'affectation ";
    printThis();
    return *this;
}

Cat::~Cat()
{
    std::cout << "Destructeur ";
    printThis();
}

//-----------------------------------------------------

void Cat::printThis()
{
    std::cout << _type << " (enfant) " << std::endl;
}

void Cat::makeSound() const
{
    std::cout << _type << " MIAOU !" << std::endl;
}