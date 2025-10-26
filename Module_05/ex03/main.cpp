#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    try
    {
        Intern someRandomIntern;
        Bureaucrat boss("Boss", 1); // Un bureaucrate avec le grade max

        // ===== Création de formulaires valides =====
        std::cout << std::endl << "=== Test des formulaires valides ===" << std::endl;

        AForm* shrubbery = someRandomIntern.makeForm("shrubbery creation", "Garden");
        AForm* robotomy  = someRandomIntern.makeForm("robotomy request", "Bender");
        AForm* pardon    = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");

        // Signature et exécution
        if (shrubbery)
        {
            boss.signForm(*shrubbery);
            boss.executeForm(*shrubbery);
        }

        if (robotomy)
        {
            boss.signForm(*robotomy);
            boss.executeForm(*robotomy);
        }

        if (pardon)
        {
            boss.signForm(*pardon);
            boss.executeForm(*pardon);
        }

        // ===== Cas d'erreur : nom inconnu =====
        std::cout << std::endl << "=== Test d'un nom inconnu ===" << std::endl;
        AForm* unknown = someRandomIntern.makeForm("pizza delivery", "Bob");
        if (!unknown)
            std::cout << "No form created for invalid request." << std::endl;

        // Libération mémoire
        delete shrubbery;
        delete robotomy;
        delete pardon;
        delete unknown; // NULL safe : ne fait rien si pointeur nul
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
