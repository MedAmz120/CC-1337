#include "Span.hpp"
#include <ctime>

int main()
{
    Span sp = Span(7);
    std::vector<int>	vect;


    srand(time(0));
	for (int i = 0; i < 6; i++)
		vect.push_back(rand() % 100);


    try {
        sp.addNumbers(vect.begin(), vect.end());
        sp.addNumber(7);
        std::cout << sp;
        std::cout << "--------" << std::endl;
        std::cout << "Shortest Span : " << sp.shortestSpan() << std::endl;
        std::cout << "Longest  Span : " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what();
    }
}