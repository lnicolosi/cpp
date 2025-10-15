#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string& name, const int gradeRequiredToSign, const int gradeRequiredToExecute)
    :   _name(name),
        _isSigned(false),
        _gradeRequiredToSign(gradeRequiredToSign),
        _gradeRequiredToExecute(gradeRequiredToExecute)
{
    if (_gradeRequiredToExecute < 1 && _gradeRequiredToSign < 1)
        throw GradeTooHighException();
    if (_gradeRequiredToExecute > 150 && _gradeRequiredToSign > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other)
    :   _name(other._name),
        _isSigned(other._isSigned),
        _gradeRequiredToSign(other._gradeRequiredToSign),
        _gradeRequiredToExecute(other._gradeRequiredToExecute) 
{

}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
    {
        _isSigned = other._isSigned;
    }
    return *this;
}

Form::~Form()
{

}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("GRADE TOO HIGH !");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("GRADE TOO LOW !");
}

const std::string& Form::getName() const
{
    return (this->_name);
}

bool Form::getIfSigned() const
{
    return (this->_isSigned);
}

int Form::getGradeRequieredToSign() const
{
    return (this->_gradeRequiredToSign);
}

int Form::getGradeRequiredToExecute() const
{
    return (this->_gradeRequiredToExecute);
}

int Form::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > this->_gradeRequiredToSign)
    {
        std::cout << b << " couldn't sign : " << std::endl << *this << "because " << std::endl;
        throw GradeTooLowException();
    }
    if (this->_isSigned)
    {
        return 2;
    }
    else
        this->_isSigned = true;
    return 1;
}

std::ostream& operator<<(std::ostream& out, const Form& f)
{
    return (out << "name : " << f.getName()
                << std::endl << "signed : " << f.getIfSigned() 
                << std::endl << "grade required to sign : " << f.getGradeRequieredToSign()
                << std::endl << "grade required to execute : " << f.getGradeRequiredToExecute()
                << std::endl); //<< "--------------------------------" << std::endl);
}