#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T, typename U>
void iter(T *array, const size_t length, void (*fonction)(U &))
{
    for(size_t i = 0; i < length; i++)
    {
        fonction(array[i]);
    }
}

#endif