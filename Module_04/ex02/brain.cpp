#include "brain.hpp"

Brain::Brain()
{
    std::cout << "Constructeur Brain ..." << std::endl;
    for (int i = 0; i < 100; ++i)
    {
        _ideas[i] = "Idée par défaut";
    }
}

Brain::Brain(const Brain& other)
{
    std::cout << "Constructeur de copie Brain." << std::endl;
    for (int i = 0; i < 100; ++i)
    {
        _ideas[i] = other._ideas[i];
    }
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Operateur d'affectation de Brain." << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; ++i)
        {
            _ideas[i] = other._ideas[i];
        }
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Destructeur de Brain." << std::endl;
}