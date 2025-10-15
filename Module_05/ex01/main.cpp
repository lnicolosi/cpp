#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b("Henry", 100);
        Form f("b12", 102, 105);
        b.signForm(f);

    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    
    return 0;
}