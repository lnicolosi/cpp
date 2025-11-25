#include "ScalarConverter.hpp"

bool isInt(std::string str)
{
    size_t i = 0;
    if (str.empty())
        return false;
    while(i < str.size() && str[i] == ' ')
        i++;
    if (str.size() == i)
        return false;
    if ((str[i] == '-' || str[i] == '+') && str.size() > i + 1)
        i++;
    for ( ; i < str.size(); i++)
    {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}
/*
char: Non displayable - impossible - value
int:
float:
double:
*/
void isImpossible()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}


void convertCharValue(char value)
{
    std::cout << std::fixed << std::setprecision(1); //afficher 1 chiffre apres la virgule float + double
    std::cout << "char: '" << value << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(value) << std::endl;
    std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void convertFloatValue(float value)
{
    if (value == static_cast<int>(value))
        std::cout << std::fixed << std::setprecision(1);
    //char    
    if (value < 0 || value >= 128)// parce que si non 127.5 (qui est DEL) devient impossible
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(value)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    //int
    if (value > static_cast<double>(INT_MAX) || value < static_cast<double>(INT_MIN))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    //float
    std::cout << "float: " << value << "f" << std::endl;
    //double
    std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void convertDoubleValue(double value)
{
    if (value == static_cast<int>(value))
        std::cout << std::fixed << std::setprecision(1);
    //char
    if (value < 0 || value >= 128)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(value)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    //int
    if (value > static_cast<double>(INT_MAX) || value < static_cast<double>(INT_MIN))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    //float
    std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    //double
    std::cout << "double: " << value << std::endl;
}

void convertIntValue(int value)
{
    if (value == static_cast<int>(value))
        std::cout << std::fixed << std::setprecision(1);
    //char
    if (value < 0 || value >= 128)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(value)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    //int
    if (value > static_cast<double>(INT_MAX) || value < static_cast<double>(INT_MIN))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    //float
    std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    //double
    std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void ScalarConverter::convert(const std::string& str)
{
    if (str.empty())
    {
        isImpossible();
        return ;
    }

    //pseudo-littéraux float
    if (str == "nanf" || str == "+inff" || str == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << str << std::endl;
        std::cout << "double: " 
                  << (str == "nanf" ? "nan" : (str[0] == '+' ? "+inf" : "-inf")) << std::endl;
        return;
    }

    //pseudo-littéraux double
    if (str == "nan" || str == "+inf" || str == "-inf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " 
                  << (str == "nan" ? "nanf" : (str[0] == '+' ? "+inff" : "-inff")) << std::endl;
        std::cout << "double: " << str << "\n";
        return;
    }
    if (str.length() == 1 && !isdigit(str[0]))
    {
        //CHAR
        char input = str[0];
        convertCharValue(input);
    }
    else if (str.find('.') != std::string::npos && str[str.length() - 1] == 'f')
    {
        //FLOAT
        std::string nof = str.substr(0, str.length() - 1);
        std::istringstream sso(nof);
        float input;
        sso >> input;
        if (sso.fail())
        {
            isImpossible();
            return ;
        }
        convertFloatValue(input);
    }
    else if (str.find('.') != std::string::npos)
    {
        //DOUBLE
        std::istringstream sso(str);
        double input;
        sso >> input;
        if (sso.fail())
        {
            isImpossible();
            return ;
        }
        convertDoubleValue(input);
    }
    else if (isInt(str))
    {
        //INT
        std::istringstream sso(str);
        int input;
        sso >> input;
        if (sso.fail())
        {
            isImpossible();
            return ;
        }
        convertIntValue(input);
    }
    else
        //IMPOSSIBLE
        isImpossible();
    return ;
}