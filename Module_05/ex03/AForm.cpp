/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolos <lnicolos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:29:57 by lnicolos          #+#    #+#             */
/*   Updated: 2025/11/19 16:29:58 by lnicolos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string& name, const int gradeRequiredToSign, const int gradeRequiredToExecute)
    :   _name(name),
        _isSigned(false),
        _gradeRequiredToSign(gradeRequiredToSign),
        _gradeRequiredToExecute(gradeRequiredToExecute)
{
    if (_gradeRequiredToExecute < 1 || _gradeRequiredToSign < 1)
        throw GradeTooHighException();
    if (_gradeRequiredToExecute > 150 || _gradeRequiredToSign > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
    :   _name(other._name),
        _isSigned(other._isSigned),
        _gradeRequiredToSign(other._gradeRequiredToSign),
        _gradeRequiredToExecute(other._gradeRequiredToExecute) 
{

}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        _isSigned = other._isSigned;
    }
    return *this;
}

AForm::~AForm()
{

}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("GRADE TOO HIGH !");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("GRADE TOO LOW !");
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return ("FORM NOT SIGNED !");
}

const std::string& AForm::getName() const
{
    return (this->_name);
}

bool AForm::getIfSigned() const
{
    return (this->_isSigned);
}

int AForm::getGradeRequieredToSign() const
{
    return (this->_gradeRequiredToSign);
}

int AForm::getGradeRequiredToExecute() const
{
    return (this->_gradeRequiredToExecute);
}

int AForm::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > this->_gradeRequiredToSign)
        throw GradeTooLowException();
    if (this->_isSigned)
        return 2;
    else
        this->_isSigned = true;
    return 1;
}

std::ostream& operator<<(std::ostream& out, const AForm& f)
{
    return (out << "FORM name : " << f.getName()
                << std::endl << "signed : " << f.getIfSigned() 
                << std::endl << "grade required to sign : " << f.getGradeRequieredToSign()
                << std::endl << "grade required to execute : " << f.getGradeRequiredToExecute()
                << std::endl); //<< "--------------------------------" << std::endl);
}