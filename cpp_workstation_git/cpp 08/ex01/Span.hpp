#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <iterator>

class Span {
    private:
    unsigned int N;
    std::vector<int> span;

    public:
    Span();
    Span(unsigned int arg) : N(arg) {};
    Span(Span const &copie);
    ~Span();
    Span& operator=(Span const &copie);

    void    addNumber(int number_to_add);
    int     shortestSpan();
    int     longestSpan();

    unsigned long getSize() const {
        return span.size();
    }
    int getElement(int i) const {
        return span[i];
    }

    template <typename input>
    void    addNumbers(input begin, input end) {
        while (begin != end)
        {
            this->addNumber(*begin);
            ++begin;
        }
    }
};

std::ostream &operator<<(std::ostream &os, Span const &sp);

#endif