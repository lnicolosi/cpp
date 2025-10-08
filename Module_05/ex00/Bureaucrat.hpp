#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <string>

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;

    public:
        //canonic construction
        Bureaucrat();
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
        const std::string& getString() const;
        const int& getGrade() const;

        //other
        void incrementGrade();
        void decrementGrade();



};


#endif