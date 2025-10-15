#include "Bureaucrat.hpp"

int main()
{
    try
    {
        // Bureaucrat b("Henry", 100);
         Form f("b12", 102, 105);
        // b.signForm(f);
        // std::cout << std::endl;
        // b.signForm(f);
        std::cout << f << std::endl;
        Bureaucrat c("Giorgia", 15);
        c.signForm(f);
        std::cout << std::endl;
        Bureaucrat d("Cristiana", 10);
        d.signForm(f);


    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    
    return 0;
}