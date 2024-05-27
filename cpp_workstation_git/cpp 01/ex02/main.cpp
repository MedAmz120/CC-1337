#include <iostream>

int main()
{
    std::string init = "HI THIS IS BRAIN";
    std::string* stringPTR = &init;
    std::string& stringREF = init;

    std::cout << &init << std::endl;
    std::cout << &stringPTR << std::endl;
    std::cout << &stringREF << std::endl;
    std::cout << init << std::endl;
    std::cout << *stringPTR << std::endl;
    std::cout << stringREF << std::endl;
    return 0;
}