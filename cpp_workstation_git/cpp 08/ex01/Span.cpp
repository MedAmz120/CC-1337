#include "Span.hpp"



/*---------------- Methods --------------------*/

void    Span::addNumber(int number_to_add)
{
    if (span.size() >= N)
        throw  std::overflow_error("Span capacity exceeded: Cannot add the specified number of elements.");
    span.push_back(number_to_add);
}

int     Span::shortestSpan() {
    
    if (span.size() < 2)
        throw std::logic_error("shortestspan requires at least two numbers");
    
    int shortestSpan = INT_MAX;
    std::vector<int> copie = span;
    std::sort(copie.begin(), copie.end());

    
    for (size_t i = 0; i < copie.size() - 1; i++) {
        int diff = copie[i + 1] - copie[i];
        if (diff < shortestSpan)
            shortestSpan = diff;
    }
    return shortestSpan;
}

int     Span::longestSpan() {
    if (span.size() < 2)
        throw std::logic_error("longestspan requires at least two numbers");

    int min = *min_element(span.begin(), span.end());
    int max = *max_element(span.begin(), span.end());

    return max - min;
}

/*------------ Operators --------------*/

std::ostream &operator<<(std::ostream &os, Span const &sp)
{
    for (size_t i = 0; i < sp.getSize(); i++) {
        os << sp.getElement(i) << std::endl;
    }

    return os;
}