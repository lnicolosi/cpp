/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolos <lnicolos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:30:01 by lnicolos          #+#    #+#             */
/*   Updated: 2025/11/19 16:30:02 by lnicolos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
        virtual ~AForm();

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