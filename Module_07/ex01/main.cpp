#include "iter.hpp"
#include <string>

// Fonctions pout int
void printInt(int &x)
{
    std::cout << x << " ";
}

void addOne(int &x)
{
    x = x + 1;
}


// Fonctions pour string
void printString(std::string &s)
{
    std::cout << s << " ";
}

void addExclamation(std::string &s)
{
    s += "!";
}

int main()
{
    //Test avec int
    int tab[] = {1, 2, 3, 4, 5};
    const size_t len = 5;

    std::cout << "Tableau au début      : ";
    iter(tab, len, printInt);
    std::cout << std::endl;

    iter(tab, len, addOne);

    std::cout << "Après un addOne sur tout : ";
    iter(tab, len, printInt);
    std::cout << std::endl;

    //Test avec strings
    std::string arr[] = {"Hello", "World", "Iter"};
    const size_t slen = 3;

    std::cout << "String - Avant addExclamation : ";
    iter(arr, slen, printString);
    std::cout << std::endl;

    iter(arr, slen, addExclamation);

    std::cout << "String - Après addExclamation : ";
    iter(arr, slen, printString);
    std::cout << std::endl;

    return 0;
}