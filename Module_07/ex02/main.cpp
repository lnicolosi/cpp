#include "Array.hpp"

int main()
{
    Array<int> list(10);

    for (int i = 0 ; i < 10 ; i++) // assignation des data de Array list
    {
        list[i] = i + 3;
    }

    list[3] = 584; //modif list -> index 3
    list[0] = 223; //modif list -> index 0

    for (int i = 0 ; i < 10 ; i++) // affichage list
    {
        std::cout << list[i] << std::endl;
    }
    std::cout << "-------" << std::endl;

    Array<int> list2(list); // constructeur de copie list dans list2
    for (int i = 0 ; i < 10 ; i++) //affichage de list2
    {
        std::cout << list2[i] << std::endl;
    }
    std::cout << "-------" << std::endl;


    list2[9] = 999; //modif de list2 -> index 9
    //list = list2; //operateur daffectation, list devient == a list2
    //au dessus si on avait pas fait la deep copy correctement la list aurait eu en index 9 une value de 999 (si on met en commentaire list = list2 )
    for (int i = 0 ; i < 10 ; i++) // affichage list pour controler si cest comme list
    {
        std::cout << list[i] << std::endl;
    }
    std::cout << "-------" << std::endl;

    try // test pour voir si lexception fonctinone bien
    {
        list[10] = 43; 
        std::cout << list[10] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}