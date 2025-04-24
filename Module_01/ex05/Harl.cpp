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
    
}