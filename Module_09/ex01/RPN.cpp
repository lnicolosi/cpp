#include "RPN.hpp"
#include <sstream>
#include <cctype>

RPN::RPN()
{

}

RPN::RPN(const RPN &other)
{
    *this = other;
}

RPN& RPN::operator=(const RPN &other)
{
    if (this != &other)
    {
        _stack = other._stack;
    }
    return *this;
}

RPN::~RPN()
{

}

bool RPN::isOperator(const std::string &token) const
{
    if (token == "+" || token == "-" || token == "*" || token == "/")
        return true;
    return false;
}

void RPN::applyOperator(char op)
{
    if (_stack.size() < 2)
        throw std::runtime_error("Error");
        
    int b = _stack.top();
    _stack.pop();
    int a = _stack.top();
    _stack.pop();

    int result = 0;
    switch (op)
    {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            if(b == 0)
                throw std::runtime_error("Error: can't divide by 0");
            result = a / b;
            break;
        default:
            throw std::runtime_error("Error: invalid operator");
    }
    _stack.push(result);
}

void RPN::evaluate(const std::string &expression)
{
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token)
    {
        if (token.length() == 1 && std::isdigit(token[0]))
            _stack.push(token[0] - '0');
        else if (isOperator(token))
            applyOperator(token[0]);
        else
            throw std::runtime_error("Error");
    }

    if (_stack.size() != 1)
        throw std::runtime_error("Error");

    std::cout << _stack.top() << std::endl;
}