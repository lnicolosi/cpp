#include "Base.hpp"

Base::~Base()
{

}

Base* generate(void)
{
    int pick = rand() % 3;
    if (pick == 0)
    {
        std::cout << "instantiate A" << std::endl;
        return new A;
    }
    else if (pick == 1)
    {
        std::cout << "instantiate B" << std::endl;
        return new B;
    }
    else if (pick == 2)
    {
        std::cout << "instantiate C" << std::endl;
        return new C;
    }
    else
    {
        //error
        std::cout << "error" << std::endl;
        return NULL;
    }
}

void identify(Base* p)
{
    if (!p)
    {
        std::cout << "pointer is NULL" << std::endl;
        return ;
    }
    if (dynamic_cast<A*>(p))
    {
        std::cout << "this pointer is A" << std::endl;
        return;
    }
    if (dynamic_cast<B*>(p))
    {
        std::cout << "this pointer is B" << std::endl;
        return;
    }
    if (dynamic_cast<C*>(p))
    {
        std::cout << "this pointer is C" << std::endl;
        return;
    }
    std::cout << "no type indentified..." << std::endl;
    return ;
}

void identify(Base& p)
{
    try 
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "this ref is A" << std::endl;
        return ;
    } catch (...) //std::bad_cast& -> possible aussi
    {
        
    }
    try 
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "this ref is B" << std::endl;
        return ;
    } catch (...)
    {
        
    }
    try 
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "this ref is C" << std::endl;
        return ;
    } catch (...)
    {
        
    }
    return ;
}