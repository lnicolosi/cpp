/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolos <lnicolos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:30:12 by lnicolos          #+#    #+#             */
/*   Updated: 2025/11/19 16:30:13 by lnicolos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{

}

Intern::Intern(const Intern&)
{

}

Intern& Intern::operator=(const Intern& other)
{
    if (this != &other)
        ;
    return *this;
}

Intern::~Intern()
{

}

static AForm* createPresidential(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

static AForm* createRobotomy(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

static AForm* createShrubbery(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}


AForm* Intern::makeForm(const std::string& formName, const std::string& formTarget)
{
    struct FormType
    {
        std::string name;
        AForm* (*create)(const std::string&);
    };

    FormType forms[] = {
        {"presidential pardon", &createPresidential},
        {"robotomy request", &createRobotomy},
        {"shrubbery creation", &createShrubbery}
    };

    for (int i = 0; i < 3; i++)
    {
        if (formName == forms[i].name)
        {
            std::cout << "Intern creates : " << forms[i].name << std::endl;
            return forms[i].create(formTarget);
        }
    }
    std::cout << "Wrong form name." << std::endl;
    return NULL;
}
