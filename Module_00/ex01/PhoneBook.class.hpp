#ifndef PHONEBOOK_CLASS_HPP
#define PHONEBOOK_CLASS_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include "Contact.class.hpp"

class PhoneBook
{
    private:
        std::string _str;
        int         _nbrContact;
        Contact     _contact[8];

    public:
        PhoneBook(void);
        ~PhoneBook(void);
        
        std::string checkString(const std::string& str);
        void        addContact();
        void        displayContact();
        void        displayContactDetail();
        bool        checkPhoneNumber(const std::string& str);
        bool        checkIfIndex(const std::string& c);
};


#endif