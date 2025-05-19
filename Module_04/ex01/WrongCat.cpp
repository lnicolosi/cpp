#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    std::cout << "Constructeur ";
    _type = "WrongCat";
    printThis();
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    std::cout << "Constructeur de copie ";
    printThis();
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    if (this != &other)
    {
        WrongAnimal::operator=(other);
    }
    std::cout << "Opérateur d'affectation ";
    printThis();
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "Destructeur ";
    printThis();
}

//-----------------------------------------------------

void WrongCat::printThis()
{
    std::cout << _type << " (enfant) " << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << _type << " MIAOU !" << std::endl;
}