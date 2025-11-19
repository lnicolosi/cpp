/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolos <lnicolos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:30:19 by lnicolos          #+#    #+#             */
/*   Updated: 2025/11/19 16:43:09 by lnicolos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    try
    {
        Intern someRandomIntern;
        Bureaucrat boss("Boss", 1); // Un bureaucrate avec le grade max

        //Création de formulaires valide
        std::cout << std::endl << "Test des formulaires valides" << std::endl;

        AForm* shrubbery = someRandomIntern.makeForm("shrubbery creation", "Garden");
        AForm* robotomy  = someRandomIntern.makeForm("robotomy request", "Dice");
        AForm* pardon    = someRandomIntern.makeForm("presidential pardon", "Matthieu");

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

        //erreur nom inconnu
        std::cout << std::endl << "Test d'un nom inconnu" << std::endl;
        AForm* unknown = someRandomIntern.makeForm("pizza delivery", "Bob");
        if (!unknown)
            std::cout << "No form created for invalid request." << std::endl;

        // free
        delete shrubbery;
        delete robotomy;
        delete pardon;
        delete unknown; // ne fait rien si pointeur nul
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
