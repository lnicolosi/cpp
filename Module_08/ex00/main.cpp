#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main()
{
    std::vector<int> v;

    // Remplir le conteneur
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(42);
    v.push_back(50);

    // Test 1 : valeur présente
    std::vector<int>::const_iterator it = easyfind(v, 42);
    if (it != v.end())
        std::cout << "Found: " << *it << std::endl;
    else
        std::cout << "42 not found" << std::endl;

    // Test 2 : valeur absente
    it = easyfind(v, 99);
    if (it != v.end())
        std::cout << "Found: " << *it << std::endl;
    else
        std::cout << "99 not found" << std::endl;

    // Test 3 : chercher la première valeur
    it = easyfind(v, 10);
    if (it != v.end())
        std::cout << "Found: " << *it << std::endl;
    else
        std::cout << "10 not found" << std::endl;

    return 0;
}
