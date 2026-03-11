#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>
void iter(T *array, const size_t length, void (*fonction)(T &))
{
    for(size_t i = 0; i < length; i++)
    {
        fonction(array[i]);
    }
}

template<typename T>
void iter(const T *array, const size_t length, void (*fonction)(const T &))
{
    for(size_t i = 0; i < length; i++)
    {
        fonction(array[i]);
    }
}

#endif