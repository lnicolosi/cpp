#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>

class RPN
{
    private:
        std::stack<int> _stack;

        bool isOperator(const std::string &token) const;
        void applyOperator(char op);

    public:
        RPN();
        RPN(const RPN &other);
        RPN& operator=(const RPN &other);
        ~RPN();

        void evaluate(const std::string &expression);
};

#endif