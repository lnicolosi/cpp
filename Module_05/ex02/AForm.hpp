#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class AForm
{
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _gradeRequiredToSign;
        const int           _gradeRequiredToExecute;


    public:
        AForm(const std::string& name, const int gradeRequiredToSign, const int gradeRequiredToExecute);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        ~AForm();

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

        class FormNotSignedException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        const std::string& getName() const;
        bool getIfSigned() const;
        int getGradeRequieredToSign() const;
        int getGradeRequiredToExecute() const;

        int beSigned(const Bureaucrat& b);

        virtual void execute(const Bureaucrat& executor) const = 0;



};

std::ostream& operator<<(std::ostream& out, const AForm& f);


#endif