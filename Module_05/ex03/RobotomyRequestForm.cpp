/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolos <lnicolos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:30:32 by lnicolos          #+#    #+#             */
/*   Updated: 2025/11/19 16:30:33 by lnicolos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    :   AForm("RobotomyRequestForm", 72, 45),
        _target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    :   AForm("RobotomyRequestForm", 72, 45),
        _target(other._target)
{

}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        _target = other._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    if (executor.getGrade() > getGradeRequiredToExecute())
        throw GradeTooLowException();
    if (!this->getIfSigned())
        throw FormNotSignedException();

    std::cout << "VVVVIIMM VVVVVIMMMM (drilling noise)..." << std::endl;

    //srand(time(0)); -> dans le main (srand = paquet de carte mélangé)
    int i = rand() % 2; // (rand = piochage de carte)
    if (i)
        std::cout << "The " << _target << " has been robotomized successfully." << std::endl;
    else
        std::cout << "Robotomy failed on " << _target << "." << std::endl;
}