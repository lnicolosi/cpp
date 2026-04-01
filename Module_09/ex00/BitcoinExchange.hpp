#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <string>

class BitcoinExchange
{
    private :
        std::map<std::string, double> _data;
        void loadData();
        bool isValidDate(const std::string &date) const;
        int isValidValue(const std::string &value) const;
        double getRate(const std::string &date) const;
        void processLine(const std::string &line) const;

    public :
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange& operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        void processInputFile(const std::string &fileName) const;
};

#endif