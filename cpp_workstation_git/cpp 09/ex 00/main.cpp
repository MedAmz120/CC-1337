#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    BitcoinExchange b1;

    if (ac != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    b1.read_data_csv();
    b1.read_input_file(av[1]);
}