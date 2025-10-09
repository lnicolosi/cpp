#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Form
{
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _gradeRequiredToSign;
        const int           _gradeRequiredToExecute;


    public:
        Form(const std::string& name, bool isSigned, const int gradeRequiredToSign, const int gradeRequiredToExecute);
        Form(const Form& other);
        const Form& operator=(const Form& other);
        ~Form();

        

}



#endif