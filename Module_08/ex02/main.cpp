#include <iostream>
#include <vector>
#include <list>
#include "MutantStack.hpp"

int main()
{
    std::cout << "Test main subject :________________" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<int> s(mstack);

    std::cout << "\nTest main subject list :________________" << std::endl;
    std::list<int> mstack2;
    mstack2.push_back(5);
    mstack2.push_back(17);
    std::cout << mstack2.back() << std::endl;
    mstack2.pop_back();
    std::cout << mstack2.size() << std::endl;
    mstack2.push_back(3);
    mstack2.push_back(5);
    mstack2.push_back(737);
    //[...]
    mstack2.push_back(0);
    std::list<int>::iterator jt = mstack2.begin();
    std::list<int>::iterator jte = mstack2.end();
    ++jt;
    --jt;
    while (jt != jte)
    {
    std::cout << *jt << std::endl;
    ++jt;
    }
    std::list<int> s2(mstack2);


    return 0;
}