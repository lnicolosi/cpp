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

};

std::ostream& operator<<(std::ostream& out, const Fixed& value);


#endif