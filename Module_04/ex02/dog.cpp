#include "dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Constructeur ";
    _type = "Dog";
    printThis();
    _brain = new Brain;

}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Constructeur de copie ";
    printThis();
    _brain = new Brain(*other._brain);

}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        if (_brain)
            delete _brain;
        
        _brain = new Brain(*other._brain);
    }
    std::cout << "Operateur d'affectation ";
    printThis();
    return *this;
}

Dog::~Dog()
{
    std::cout << "Destructeur ";
    printThis();
    delete _brain;
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



