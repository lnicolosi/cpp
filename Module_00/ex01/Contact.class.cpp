#include "Contact.class.hpp"

Contact::Contact(void)
{
    _firstName = "empty";
    _lastName = "empty";
    _nickname = "empty";
    _phoneNumber = "empty";
    _darkestSecret = "empty";
    return;
}

Contact::~Contact(void)
{
    return;  
}

void Contact::set_firstName(const std::string& firstName)
{
    _firstName = firstName;
}

void Contact::set_lastName(const std::string& lastName)
{
    _lastName = lastName;
}

void Contact::set_nickname(const std::string& nickname)
{
    _nickname = nickname;
}

void Contact::set_phoneNumber(const std::string& phoneNumber)
{
    _phoneNumber = phoneNumber;
}

void Contact::set_darkestSecret(const std::string& darkerstSecret)
{
    _darkestSecret = darkerstSecret;
}

const std::string& Contact::get_firstName() const
{
    return _firstName;
}

const std::string& Contact::get_lastName() const
{
    return _lastName;
}

const std::string& Contact::get_nickname() const
{
    return _nickname;
}

const std::string& Contact::get_phoneNumber() const
{
    return _phoneNumber;
}

const std::string& Contact::get_darkestSecret() const
{
    return _darkestSecret;
}
