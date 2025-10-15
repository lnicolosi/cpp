#ifndef FORM_HPP
#define FORM_HPP


#include <iostream>
#include <string>
//#include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _gradeRequiredToSign;
        const int           _gradeRequiredToExecute;


    public:
        Form(const std::string& name, const int gradeRequiredToSign, const int gradeRequiredToExecute);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        const std::string& getName() const;
        bool getIfSigned() const;
        int getGradeRequieredToSign() const;
        int getGradeRequiredToExecute() const;

        int beSigned(const Bureaucrat& b);



};

std::ostream& operator<<(std::ostream& out, const Form& f);


#endif