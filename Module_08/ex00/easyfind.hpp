#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template<typename T>
typename T::const_iterator easyfind(const T &container, int n);

#include "easyfind.tpp"
#endif