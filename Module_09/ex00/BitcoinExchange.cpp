#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <fstream>
#include <stdexcept>

void BitcoinExchange::loadData()
{
    std::ifstream file("data.csv");
    if (!file.is_open())
        throw std::runtime_error("Error: could not open data.csv");

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line))
    {
        if(line.empty())
            continue;
        size_t pos = line.find(',');
        if (pos == std::string::npos)
            continue;
        std::string date = line.substr(0, pos);
        std::string taux = line.substr(pos + 1);

        double val = std::strtod(taux.c_str(), NULL);
        _data.insert(std::make_pair(date, val));
    }
}

double BitcoinExchange::getRate(const std::string &date) const
{
    std::map<std::string, double>::const_iterator it;
    it = _data.lower_bound(date);
    if (_data.empty())
        throw std::runtime_error("Error: empty database.");
    if (it == _data.end())
    {
        --it;
        return it->second;
    }
    if(it == _data.begin() && it->first != date)
    {
        throw std::runtime_error("Error: no anterior date.");
    }
    if (it->first != date)
        --it;
    return it->second;
}

static std::string trim(const std::string& str)
{
    size_t start = 0;
    while (start < str.size() && str[start] == ' ')
        start++;

    size_t end = str.size();
    while (end > start && str[end - 1] == ' ')
        end--;

    return str.substr(start, end - start);
}

void BitcoinExchange::processLine(const std::string &line) const
{
    size_t pos = line.find('|');
    if (pos == std::string::npos)
    {
        //Error: bad input => 2001-42-42
        std::cout << "Error: bad input => " << line << std::endl;
        return ;
    }

    std::string date = line.substr(0, pos);
    std::string sval = line.substr(pos + 1);
    date = trim(date);
    sval = trim(sval);
    
    if (!isValidDate(date))
    {
        std::cout << "Error: bad input => " << line << std::endl;
        return ;
    }
    int status = isValidValue(sval);
    if (status == 0)
    {
        //Error: not a positive number.
        std::cout << "Error: not a positive number." << std::endl;
        return ;
    }
    else if (status == 1)
    {
        //Error: too large a number.
        std::cout << "Error: too large a number." << std::endl;
        return ;
    }
    else if (status == 2)
    {
        //other error
        std::cout << "Error: bad input => " << line << std::endl;
        return ;
    }
    double rate;
    double val = std::strtod(sval.c_str(), NULL);
    try 
    {
        rate = getRate(date);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return ;
    }
    double result = val * rate;

    std::cout << date << " => " << val << " = " << result << std::endl;
    return ;
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
    if (date.size() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    for (size_t i = 0; i < date.length(); i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(date[i]))
            return false;
    }
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12)
        return false;

    if (day < 1)
        return false;

    int maxDay;

    if (month == 2)
    {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            maxDay = 29;
        else
            maxDay = 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        maxDay = 30;
    else
        maxDay = 31;

    if (day > maxDay)
        return false;

    return true;
}

int BitcoinExchange::isValidValue(const std::string& value) const
{
    if (value.empty())
        return 2;

    char* end;
    double dvalue = std::strtod(value.c_str(), &end);

    if (*end != '\0')
        return 2;

    if (dvalue < 0)
        return 0;

    if (dvalue > 1000)
        return 1;

    return 3;
}

BitcoinExchange::BitcoinExchange()
{
    loadData();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _data(other._data)
{

}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        _data = other._data;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{

}

void BitcoinExchange::processInputFile(const std::string &fileName) const
{
    std::ifstream file(fileName.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open input file.");

    std::string line;

    // skip header
    if (!std::getline(file, line))
        return;

    while (std::getline(file, line))
    {
        if (line.empty())
            continue;
        processLine(line);
    }
}