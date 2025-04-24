#include <iostream>
#include <string>

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    
    if (argc == 2)
    {
        std::string str = argv[1];
        for (size_t i = 0; i < str.length(); i++)
        {
            str[i] = std::toupper(str[i]);
        }
        std::cout << str << std::endl;
    }
    else
    {
        std::string str;
        for(int i = 1; i < argc; i++)
        {
            str.append(argv[i]);
        }

        for (size_t i = 0; i < str.length(); i++)
        {
            str[i] = std::toupper(str[i]);
        }

        std::cout << str << std::endl;
    }

    return 0;
}