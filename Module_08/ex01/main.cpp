#include <iostream>
#include <vector>
#include "Span.hpp"

int main()
{
    std::cout << "BASIC TEST :___________" << std::endl;

    try
    {
        Span sp(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\nTEST addMultipleNumber : ______________" << std::endl;

    try
    {
        Span sp2(10);

        std::vector<int> v;
        v.push_back(10);
        v.push_back(20);
        v.push_back(30);
        v.push_back(40);
        v.push_back(50);

        sp2.addMultipleNumber(v.begin(), v.end());

        std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\nTEST SPAN FULL : ______________" << std::endl;

    try
    {
        Span sp3(3);

        sp3.addNumber(1);
        sp3.addNumber(2);
        sp3.addNumber(3);

        sp3.addNumber(4); // doit throw
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\nTEST NO SPAN: _________________" << std::endl;

    try
    {
        Span sp4(5);

        sp4.addNumber(42);

        std::cout << sp4.shortestSpan() << std::endl; // doit throw
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\nTEST WITH DUPLICATES: ___________________" << std::endl;

    try
    {
        Span sp5(5);

        sp5.addNumber(5);
        sp5.addNumber(5);
        sp5.addNumber(10);

        std::cout << "Shortest span: " << sp5.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp5.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\nTEST 10000 NUMBERS : __________________" << std::endl;

    try
    {
        Span big(10000);
        std::vector<int> v;

        for (int i = 0; i < 10000; i++)
            v.push_back(i);

        big.addMultipleNumber(v.begin(), v.end());

        std::cout << "Shortest span: " << big.shortestSpan() << std::endl;
        std::cout << "Longest span: " << big.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}