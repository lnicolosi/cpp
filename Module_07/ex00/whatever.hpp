#ifndef WHATEVER_HPP
#define WHATEVER_HPP


template<typename T> 
void swap(T &x, T &y)
{
    T temp = x;
    x = y;
    y = temp;
}

template<typename T>
const T &min(T const &x, T const &y)
{
    if (x < y)
        return x;
    else
        return y;
}

template<typename T>
T max(T x, T y)
{
    if (x > y)
        return x;
    else
        return y;
}


#endif