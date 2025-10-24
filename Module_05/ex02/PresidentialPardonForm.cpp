#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    :   AForm("PresidentialPardonForm", 25, 5),
        _target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    :   AForm("PresidentialPardonForm", 25, 5),
        _target(other._target)
{

}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if(this != &other)
    {
        _target = other._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
    if (executor.getGrade() > getGradeRequiredToExecute())
        throw GradeTooLowException();
    if (!this->getIfSigned())
        throw FormNotSignedException();
        
    std::cout << "We inform you that " << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}