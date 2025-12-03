#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>

template<typename T>
class Array
{
    private:
        unsigned int _size;
        T* _data;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array &other);
        Array& operator=(const Array &other);
        ~Array();

        unsigned int size() const;
        T& operator[](unsigned int index);
        const T& operator[](unsigned int index) const;
};


#include "Array.tpp"
#endif