/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolos <lnicolos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:30:04 by lnicolos          #+#    #+#             */
/*   Updated: 2025/11/19 16:30:05 by lnicolos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) 
    :   _name(name),
        _grade(grade)
{
    if (this->_grade < 1)
        throw GradeTooHighException();
    if (this->_grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    :   _name(other._name),
        _grade(other._grade)
{

}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        _grade = other._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{

}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return("GRADE TOO HIGH"); //class interne
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return("GRADE TOO LOW");
}


const std::string& Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}



void Bureaucrat::incrementGrade()
{
    if (this->_grade <= 1)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade()
{
    if (this->_grade >= 150)
        throw GradeTooLowException();
    _grade++;
}

void Bureaucrat::signForm(AForm& f)
{
    try
    {
        int res = f.beSigned(*this);
        if(res == 1)
            std::cout << this->_name << " signed : " << f.getName() << std::endl;
        else if (res == 2)
            std::cout << this->_name << " couldn't sign : " << f.getName() << " because it is already signed." << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << this->_name << " couldn't sign : " << f.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(const AForm& form)
{
    try
    {
        form.execute(*this);
        std::cout << this->_name << " executed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << this->_name << " couldn't execute : " << std::endl << form.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b)
{
    return out << "BUREAUCRAT name : " << b.getName() << ", bureaucrat grade " << b.getGrade();
}
