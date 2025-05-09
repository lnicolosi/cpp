#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
    private:
        int _fixedPointValue;
        static const int _fractionalBit = 8;

    public:
        Fixed(void);                        //constructeur par DEFAUT
        Fixed(const Fixed &src);            //constructeure de COPIE
        Fixed& operator=(const Fixed &src); //OPERATEUR d'affection
        ~Fixed(void);                       //DESTRUCTEUR

        int getRawBits() const;
        void setRawBits(int const rawBits);

};



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


#endif