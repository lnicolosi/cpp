#include "Harl.hpp"
#include <iostream>
#include <string>


int main()
{
    std::string level;
    do
    {
        std::cout << "chose what level of message you want to display :" << std::endl;
        std::cout << "DEBUG || INFO || WARNING || ERROR" << std::endl;
        std::cin >> level;
        
    } while (level != "DEBUG" && level != "INFO" && level != "WARNING" && level != "ERROR");


    
    Harl harl;
    harl.complain(level);


    return 0;
}