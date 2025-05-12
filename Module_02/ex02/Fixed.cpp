#include "Fixed.hpp"


Fixed::Fixed(void) : _fixedPointValue(0)
{
    //std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
    //std::cout << "Copy constructor called" << std::endl;
    this->_fixedPointValue = src.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &src)
{
    //std::cout << "Copy assignment operator called" << std::endl;
    if (this != &src)
        this->_fixedPointValue = src.getRawBits();
    return *this;
}

Fixed::~Fixed(void)
{
    //std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    //std::cout << "Int constructor called" << std::endl;
    _fixedPointValue = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
    //std::cout << "Float constructor called" << std::endl;
    _fixedPointValue = roundf(value * (1 << _fractionalBits));
}

int Fixed::getRawBits() const
{
    //std::cout << "GetRawBits member function called" << std::endl;
    return _fixedPointValue;
}


void Fixed::setRawBits(int const rawBits)
{
    _fixedPointValue = rawBits;
}

float Fixed::toFloat() const
{
    return (static_cast<float>(_fixedPointValue) / (1 << _fractionalBits));
}


int Fixed::toInt() const
{
    return _fixedPointValue >> _fractionalBits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& value)
{
    out << value.toFloat();
    return out;
}


//operateur de comparaison
bool Fixed::operator>(const Fixed& other) const 
{
    return this->_fixedPointValue > other._fixedPointValue;
}

bool Fixed::operator<(const Fixed& other) const
{
    return this->_fixedPointValue < other._fixedPointValue;
}

bool Fixed::operator>=(const Fixed& other) const
{
    return this->_fixedPointValue >= other._fixedPointValue;
}

bool Fixed::operator<=(const Fixed& other) const
{
    return this->_fixedPointValue <= other._fixedPointValue;
}

bool Fixed::operator==(const Fixed& other) const
{
    return this->_fixedPointValue == other._fixedPointValue;
}

bool Fixed::operator!=(const Fixed& other) const
{
    return this->_fixedPointValue != other._fixedPointValue;
}

//opérateurs
Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed result;
    result.setRawBits(this->_fixedPointValue + other._fixedPointValue);
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed result;
    result.setRawBits(this->_fixedPointValue - other._fixedPointValue);
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed result;
    long tmp = static_cast<long>(this->_fixedPointValue) * other._fixedPointValue;
    result.setRawBits(static_cast<int>(tmp >> _fractionalBits));
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
    if (other._fixedPointValue == 0) 
    {
        std::cerr << "Not possible to divide by 0..." << std::endl;
        return Fixed();
    }
    Fixed result;
    long tmp = (static_cast<long>(this->_fixedPointValue) << _fractionalBits) / other._fixedPointValue;
    result.setRawBits(static_cast<int>(tmp));
    return result;
}

 //opérateur incrémentation et décrémentation
Fixed& Fixed::operator++() 
{
    ++_fixedPointValue;
    return *this;
}

Fixed& Fixed::operator--()
{
    --_fixedPointValue;
    return *this;
}

Fixed Fixed::operator++(int) 
{
    Fixed temp(*this);
    ++_fixedPointValue;
    return temp;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    --_fixedPointValue;
    return temp;
}

//max / min
Fixed& Fixed::min(Fixed& a, Fixed& b) 
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) 
{
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) 
{
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) 
{
    return (a > b) ? a : b;
}
