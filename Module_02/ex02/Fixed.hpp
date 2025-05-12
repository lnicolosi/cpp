#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
    private:
        int                 _fixedPointValue;
        static const int    _fractionalBits = 8;

    public:
        Fixed(void);                        //constructeur par DEFAUT
        Fixed(const Fixed &src);            //constructeure de COPIE
        Fixed& operator=(const Fixed &src); //OPERATEUR d'affection
        ~Fixed(void);                       //DESTRUCTEUR
        Fixed(const int value);
        Fixed(const float value);

        int getRawBits() const;
        void setRawBits(int const rawBits);
        float toFloat() const;
        int toInt() const;

        //operateur de comparaison
        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;

        //opérateurs
        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;

        //opérateur incrémentation et décrémentation
        Fixed& operator++();      // pré-incrémentation
        Fixed operator++(int);    // post-incrémentation
        Fixed& operator--();      // pré-décrémentation
        Fixed operator--(int);    // post-décrémentation

        //max / min
        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);



};

std::ostream& operator<<(std::ostream& out, const Fixed& value);


#endif