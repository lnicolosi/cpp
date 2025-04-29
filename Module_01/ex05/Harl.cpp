#include "Harl.hpp"

// constructeur
Harl::Harl(void)
{

}

// destructeur
Harl::~Harl(void)
{

}

void Harl::_debug(void)
{
    std::cout << "hello Harl is DEBUGING !" << std::endl;
}

void Harl::_info(void)
{
    std::cout << "hello Harl can INFOrm you !" << std::endl;
}

void Harl::_warning(void)
{
    std::cout << "hello Harl is WARNING you !" << std::endl;
}

void Harl::_error(void)
{
    std::cout << "hello Harl also somtimes makes ERRORs !" << std::endl;
}


void Harl::complain(std::string level)
{
    // 1. Tableau de strings ["DEBUG", "INFO", ...]
    std::string input[4] = {"DEBUG", "INFO", "WARNING", "ERROR"}; 
    // 2. Tableau de pointeurs sur fonctions membres [&Harl::debug, &Harl::info, ...]
    void (Harl::*ptr[])() =
    {
        &Harl::_debug,
        &Harl::_info,
        &Harl::_warning,
        &Harl::_error
    };
    // 3. Boucle pour comparer l'entrée "level" et appeler la bonne fonction via pointeur
    for (int i = 0; i < 4; ++i)
    {
        if (input[i] == level)
        {
            (this->*ptr[i])();
            return;
        }
    }
}
