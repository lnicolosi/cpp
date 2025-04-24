#include "PhoneBook.class.hpp"


// Default constructor
/*PhoneBook::PhoneBook(void)
{
    _nbrContact = 0;
    return;
}
*/

// Constructor for debug

PhoneBook::PhoneBook(void)
{    
    _contact[0].set_firstName("Luca");
    _contact[0].set_lastName("Nicolosi");
    _contact[0].set_nickname("Eklerk");
    _contact[0].set_phoneNumber("0795355818");
    _contact[0].set_darkestSecret("lol");

    _contact[1].set_firstName("Marzia");
    _contact[1].set_lastName("Nicolosi");
    _contact[1].set_nickname("Marsoin");
    _contact[1].set_phoneNumber("04298388");
    _contact[1].set_darkestSecret("lol");

    _contact[2].set_firstName("Catherine");
    _contact[2].set_lastName("Deneuve");
    _contact[2].set_nickname("Cathedeneuve");
    _contact[2].set_phoneNumber("429756129");
    _contact[2].set_darkestSecret("lol");

    _contact[3].set_firstName("Jean-Pascalo");
    _contact[3].set_lastName("Dos Santos Nunes");
    _contact[3].set_nickname("Portugais");
    _contact[3].set_phoneNumber("30820");
    _contact[3].set_darkestSecret("lol");

    _contact[4].set_firstName("Luca");
    _contact[4].set_lastName("Nicolosi");
    _contact[4].set_nickname("Eklerk");
    _contact[4].set_phoneNumber("0795355818");
    _contact[4].set_darkestSecret("lol");

    _contact[5].set_firstName("Luca");
    _contact[5].set_lastName("Nicolosi");
    _contact[5].set_nickname("Eklerk");
    _contact[5].set_phoneNumber("0795355818");
    _contact[5].set_darkestSecret("lol");

    _contact[6].set_firstName("Luca");
    _contact[6].set_lastName("Nicolosi");
    _contact[6].set_nickname("Eklerk");
    _contact[6].set_phoneNumber("0795355818");
    _contact[6].set_darkestSecret("lol");

    _contact[7].set_firstName("Luca");
    _contact[7].set_lastName("Nicolosi");
    _contact[7].set_nickname("Eklerk");
    _contact[7].set_phoneNumber("0795355818");
    _contact[7].set_darkestSecret("lol");

    _nbrContact = 7;
}



PhoneBook::~PhoneBook(void)
{
    return;  
}

std::string PhoneBook::checkString(const std::string& str)
{
    size_t len = str.length();
    if (len > 10)
    {
        return (str.substr(0, 9) + "."); //coupe la string apres 9 char et rajoute un "."
    }
    
    return (str);
}

bool PhoneBook::checkPhoneNumber(const std::string& str)
{
    if (str.length() != 10)
    {
        std::cout << "Phone number is 10 digit !" << std::endl;
        return false;
    }
    
    for (size_t i = 0; i < str.length(); ++i) 
    {
        if (!isdigit(str[i]))
        {
            std::cout << "Phone number is only digits from 0 to 9 !" << std::endl;
            return false;
        }
    }

    return true;
}


void PhoneBook::addContact()
{
    do //first name
    {
        std::cout << "Enter contact's first name : ";
        std::getline(std::cin, _str);
    } while (_str.empty());
    _contact[_nbrContact].set_firstName(_str);
        
    do //last name
    {
        std::cout << "Enter contact's last name : ";
        std::getline(std::cin, _str);
    } while (_str.empty());
    _contact[_nbrContact].set_lastName(_str);
        
    do //nickname
    {
        std::cout << "Enter contact's nickname : ";
        std::getline(std::cin, _str);
    } while (_str.empty());
    _contact[_nbrContact].set_nickname(_str);

    do //phone number
    {
        std::cout << "Enter contact's phone number : ";
        std::getline(std::cin, _str);
    } while(!checkPhoneNumber(_str));
    _contact[_nbrContact].set_phoneNumber(_str);

    do //darkest secret
    {
        std::cout << "Enter contact's darkest secret : ";
        std::getline(std::cin, _str);
    } while (_str.empty());
    _contact[_nbrContact].set_darkestSecret(_str);

    if (_nbrContact < 7)
        _nbrContact++;
}



void PhoneBook::displayContact()
{
    int i = 0;
    std::cout   << std::setw(10) << std::right << "INDEX" << "|" 
                << std::setw(10) << std::right << "FIRST NAME" << "|"  
                << std::setw(10) << std::right << "LAST NAME" << "|" 
                << std::setw(10) << std::right << "NICKNAME" << std::endl;
    while (i < 8)
    {       
        std::cout << std::setw(10) << std::right << i + 1  << "|" ;
        std::cout << std::setw(10) << std::right << checkString(_contact[i].get_firstName()) << "|" ;
        std::cout << std::setw(10) << std::right << checkString(_contact[i].get_lastName()) << "|" ;
        std::cout << std::setw(10) << std::right << checkString(_contact[i].get_nickname()) << std::endl;
        i++;
    }
}

bool PhoneBook::checkIfIndex(const std::string& c)
{
    if (std::string("12345678").find(c) == std::string::npos)
    {
        std::cout << "Wrong digit, only from 1 to 8" << std::endl;
        return false;
    }
    else if (c.empty())
        return false;
    return true;
}

void PhoneBook::displayContactDetail()
{
    std::string c;
    do
    {
        std::cout << "Select an index from 1 to 8 to show contact's infos" << std::endl;
        std::getline(std::cin, c);
    } while(!checkIfIndex(c));

    int i = std::stoi(c) - 1; //string to int

    std::cout << std::endl;
    std::cout << _contact[i].get_firstName() << std::endl;
    std::cout << _contact[i].get_lastName() << std::endl; 
    std::cout << _contact[i].get_nickname() << std::endl;
    std::cout << _contact[i].get_phoneNumber() << std::endl;
    std::cout << _contact[i].get_darkestSecret() << std::endl;
}

