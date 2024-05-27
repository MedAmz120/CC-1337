#include "Sed.hpp"

int main(int ac, char **av)
{
    if (ac == 4)
    {
        args data(av[1], av[2], av[3]); // i initialize the src file name, s1 and s2
        if (!data.src.is_open())
            quit_program (EXIT_FAILURE, "ERROR:unable to open input file\n");
        ft_sed(&data);
        data.src.close();
        std::cout << "Replacement completed.";
    }
    else
        std::cerr << "Invalid arguments\n" << "Usage <filename> <s1> <s2>";
    return (0);
}