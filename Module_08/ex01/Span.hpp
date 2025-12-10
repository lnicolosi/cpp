#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>

class Span
{
    private:
        unsigned int _N;
        std::vector<int> _values;

    public:
        Span(unsigned int N);
        Span(const Span &other);
        Span& operator=(const Span &other);
        ~Span();

        void addNumber(const int n);
        int shortestSpan() const;
        int longestSpan() const;
};


#endif