#include "Fixed.hpp"


Fixed::Fixed(void) : _fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_fixedPointValue = src.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &src)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &src)
        this->_fixedPointValue = src.getRawBits();
    return *this;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    _fixedPointValue = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    _fixedPointValue = roundf(value * (1 << _fractionalBits));
}

int Fixed::getRawBits() const
{
    std::cout << "GetRawBits member function called" << std::endl;
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

