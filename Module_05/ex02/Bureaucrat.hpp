#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <string>
#include "Form.hpp"

class Bureaucrat
{
    private:
        const std::string   _name;
        int                 _grade;

    public:
        //canonic construction
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();


        //exceptions
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

        //getters
        const std::string& getName() const;
        int getGrade() const;

        //other
        void incrementGrade();
        void decrementGrade();

        //ex01
        void signForm(Form& f);
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);


#endif