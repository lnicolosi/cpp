#include "animal.hpp"
#include "dog.hpp"
#include "cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{

    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;
    
    return 0;
    // std::cout << "------ Création d’un Cat original ------" << std::endl;
    // Cat cat1;
    
    // std::cout << "\n------ Test constructeur de copie ------" << std::endl;
    // Cat cat2(cat1);

    // std::cout << "\n------ Test opérateur d’affectation ------" << std::endl;
    // Cat cat3;
    // cat3 = cat1;

    // std::cout << "\n------ Suppression des objets ------" << std::endl;
    // return 0; 

}