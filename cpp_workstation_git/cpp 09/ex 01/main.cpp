#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error: usage: <RPN>" << std::endl;
        return 1;
    }

    try {
        RPN r;
        std::cout << r.rpn_calculation(av[1]) << std::endl;
    }
    catch (const std::logic_error &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}