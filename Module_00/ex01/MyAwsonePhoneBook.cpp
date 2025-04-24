#include <iostream>
#include <string>
#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"

int main()
{
    std::string choice;
    PhoneBook phoneBook;
    

    while (choice != "EXIT" && choice != "exit")
    {
        do {
            std::cout << std::endl << "Select one of these commands:\n";
            std::cout << "[ADD] -- [SEARCH] -- [EXIT]" << std::endl;
            std::cout << "> ";
            std::getline(std::cin, choice);  
            } while (choice.empty() || 
                    (choice != "ADD" && choice != "add" && 
                     choice != "SEARCH" && choice != "search" && 
                     choice != "EXIT" && choice != "exit"));

        if (choice == "ADD" || choice == "add")
        {
            std::cout << "Add contact" << std::endl;
            phoneBook.addContact();
        }

        else if (choice == "SEARCH" || choice == "search")
        {
            std::cout << "Search contact" << std::endl;
            phoneBook.displayContact();    
            phoneBook.displayContactDetail();
        }

        else if (choice == "EXIT" || choice == "exit")
            std::cout << "Exit program" << std::endl;
        else
        {
            std::cout << "Erreur" << std::endl;
            return 1;
        }
    }

    return 0;
    
}