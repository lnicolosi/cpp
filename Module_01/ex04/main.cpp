#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
    //check argument
    if (argc != 4)
    {
        std::cout << "Input must be the following :\n" << "NAME OF FILE | " << "String 1 | " << "String 2" << std::endl;
        return 1;
    }
    for (int i = 1; i < argc; i++)
    {
        std::cout << argv[i] << " | ";
    }
    std::cout << std::endl;

    //check file
    std::string toReplace = argv[2]; //s1
    std::string replacedBy = argv[3]; //s2

    std::ifstream inFile(argv[1]);
    if (inFile.fail())
    {
        std::cerr << "Impossible d'utiliser le fichier de lecture..." << std::endl;
        return 1;
    }
    std::string replacedFile = std::string(argv[1]) + ".replace";
    std::ofstream outFile(replacedFile);
    if (outFile.fail())
    {
        std::cerr << "Impossible d'utiliser le fichier d'écriture..." << std::endl;
        return 1;
    }

    //replace occurance and copy in new file
    std::string line;
    while(std::getline(inFile, line))
    {
        size_t pos = line.find(toReplace);
        while(pos != std::string::npos)
        {
            std::string before = line.substr(0, pos);
            std::string after = line.substr(pos + toReplace.length());
            line = before + replacedBy + after;
            pos = line.find(toReplace, pos + replacedBy.length());
        }
        outFile << line << std::endl;
    }

    inFile.close();
    outFile.close();

    return 0;
}