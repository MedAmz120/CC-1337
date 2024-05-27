#include <iostream>

bool check_char(char c)
{
    return (c >= 97 && c <= 122);
}

int main(int argc, char **argv)
{
    int i;
    int j;

    i = 0;
    if (argc > 1)
    {
        while (argv[++i])
        {
            j = -1;
            while (argv[i][++j])
            {
                if (check_char(argv[i][j]))
                    std::cout << static_cast<char>(argv[i][j] - 32);
                else
                    std::cout << argv[i][j];
            }
        }
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::cout << "\n";
    return (1);
}
