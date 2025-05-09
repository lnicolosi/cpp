// #ifndef MYCLASS_HPP
// #define MYCLASS_HPP

// class MyClass
// {
// public:
//     MyClass();                                   // Constructeur par défaut
//     MyClass(const MyClass& other);               // Constructeur de copie
//     MyClass& operator=(const MyClass& other);    // Opérateur d'affectation
//     ~MyClass();                                  // Destructeur

// private:
//     int _value; // Attribut privé exemple
// };

// #endif // MYCLASS_HPP


#include "Fixed.hpp"

int main()
{
    Fixed a;
    Fixed b( a );
    Fixed c;
    c = b;
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    return 0;
}