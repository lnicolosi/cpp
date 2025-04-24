#ifndef CONTACT_CLASS_HPP
#define CONTACT_CLASS_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
    private:
        std::string _firstName;
        std::string _lastName;
        std::string _nickname;
        std::string _phoneNumber;
        std::string _darkestSecret;

    public:
        Contact(void);
        ~Contact(void);

        void    set_firstName(const std::string& firstName);
        void    set_lastName(const std::string& lastName);
        void    set_nickname(const std::string& nickname);
        void    set_phoneNumber(const std::string& phoneNumber);
        void    set_darkestSecret(const std::string& darkestSecret);
        const std::string& get_firstName() const;
        const std::string& get_lastName() const;
        const std::string& get_nickname() const;
        const std::string& get_phoneNumber() const;
        const std::string& get_darkestSecret() const;
};


#endif