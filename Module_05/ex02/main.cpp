#include "Bureaucrat.hpp"
#include <ctime>


int main()
{
    srand(time(0));
    try
    {
        Bureaucrat bob("Bob", 130);
        Bureaucrat test("alex", 40);
        ShrubberyCreationForm form("garden");
        RobotomyRequestForm form2("Silver");

        std::cout << bob << std::endl;
        std::cout << form << std::endl;
        std::cout << form2 << std::endl;

        bob.signForm(form);       // test de signature
        bob.executeForm(form);    // test d'exécution
        bob.executeForm(form);
        test.signForm(form);
        test.signForm(form2);
        test.executeForm(form2);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}