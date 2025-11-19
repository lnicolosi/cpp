/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolos <lnicolos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:29:51 by lnicolos          #+#    #+#             */
/*   Updated: 2025/11/19 16:29:52 by lnicolos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    :   AForm("Shrubbery Creation Form", 145, 137),
        _target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    :   AForm("Shrubbery Creation Form", 145, 137),
        _target(other._target)
{

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        _target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    if (executor.getGrade() > getGradeRequiredToExecute())
        throw GradeTooLowException();
    if (!this->getIfSigned())
        throw FormNotSignedException();
    
    std::cout << "Form executing..." << std::endl;
    std::ofstream file((_target + "_shrubbery").c_str(), std::ios::app);
    file << "      ### " << std::endl <<
    "     #o### " << std::endl <<
    "   #####o### " <<std::endl <<
    "  #o#\\#|#/### " << std::endl <<
    "   ###\\|/#o# " << std::endl <<
    "    # }|{  # " << std::endl <<
    "      }|{ " << std::endl <<
    std::endl;
}