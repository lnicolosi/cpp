/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolos <lnicolos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:29:27 by lnicolos          #+#    #+#             */
/*   Updated: 2025/11/19 16:29:28 by lnicolos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

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
        void signForm(AForm& f);

        //ex02
        void executeForm(const AForm& form);
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);


#endif