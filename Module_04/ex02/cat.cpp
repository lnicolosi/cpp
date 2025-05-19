#include "cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << "Constructeur ";
    _type = "Cat";
    printThis();
    _brain = new Brain;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Constructeur de copie ";
    printThis();
    _brain = new Brain(*other._brain);
  
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        if (_brain)
            delete _brain;
        
        _brain = new Brain(*other._brain);
    }
    std::cout << "Opérateur d'affectation ";
    printThis();
    return *this;
}

Cat::~Cat()
{
    std::cout << "Destructeur ";
    printThis();
    delete _brain;
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