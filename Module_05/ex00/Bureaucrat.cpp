#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) 
    :   _name(name),
        _grade(grade)
{
    if (this->_grade < 1)
        throw GradeTooHighException();
    if (this->_grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{

}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{

}

Bureaucrat::~Bureaucrat()
{

}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return("note deja au max"); //class interne
}

void Bureaucrat::incrementGrade()
{
    if (this->_grade <= 1)
        throw GradeTooHighException();
    _grade--;
}

