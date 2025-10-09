#include "Bureaucrat.hpp"

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


std::ostream& operator<<(std::ostream& out, const Bureaucrat& b)
{
    return out << b.getName() << ", bureaucrat grade " << b.getGrade();
}
