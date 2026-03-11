#include "Span.hpp"

Span::Span(unsigned int N) : _N(N)
{

}

Span::Span(const Span& other) : _N(other._N)
{

}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _N = other._N;
    }
    return *this;
}

Span::~Span()
{

}

void Span::addNumber(const int n)
{
    if (_values.size() >= _N)
    {
        throw FullSpan();
    }
    _values.push_back(n);
}

int Span::shortestSpan() const
{
    if (_values.size() < 2)
    {
        throw NoSpan();
    }
    std::vector<int> v = _values;
    std::sort(v.begin(), v.end());

    std::vector<int>::const_iterator it = v.begin();
    int span = 0;
    int shortestSpan = *(it + 1) - *it;


    while (it < (v.end() - 1))
    {
        span = *(it + 1) - *it;
        if (span < shortestSpan)
        {
            shortestSpan = span;
        }
        ++it;
    }
    return shortestSpan;
}

int Span::longestSpan() const
{
    if (_values.size() < 2)
    {
        throw NoSpan();
    }
    int max = *std::max_element(_values.begin(), _values.end());
    int min = *std::min_element(_values.begin(), _values.end());
    return max - min ;
}

const char* Span::FullSpan::what() const throw()
{
    return "Span is full";
}

const char* Span::NoSpan::what() const throw()
{
    return "No span can be found";
}