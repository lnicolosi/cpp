#include "Bureaucrat.hpp"








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

