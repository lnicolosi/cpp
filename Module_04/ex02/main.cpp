#include "animal.hpp"
#include "dog.hpp"
#include "cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{

    std::cout << ">>> Création d'un tableau de Animal*" << std::endl;

    const int size = 4;
    Animal* animals[size];

    for (int i = 0; i < size; ++i)
    {
        if (i < size / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\n>>> Appels à makeSound()" << std::endl;
    for (int i = 0; i < size; ++i)
    {
        animals[i]->makeSound();
    }

    std::cout << "\n>>> Suppression des animaux" << std::endl;
    for (int i = 0; i < size; ++i)
    {
        delete animals[i];
    }

    std::cout << "\n>>> Tentative d'instancier Animal (devrait échouer si décommenté)" << std::endl;
    // Animal* a = new Animal(); // ❌ doit échouer à la compilation


}