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
        
        template<typename Iterator>
        void addMultipleNumber(Iterator begin, Iterator end);

        class FullSpan : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class NoSpan : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

template<typename Iterator>
void Span::addMultipleNumber(Iterator begin, Iterator end)
{
    while (begin != end)
    {
        addNumber(*begin);
        ++begin;
    }
}

#endif