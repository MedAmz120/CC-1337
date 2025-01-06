#include "easyfind.hpp"

int main()
{
    std::vector<int> numbers;

    numbers.push_back(141);
    numbers.push_back(2434);
    numbers.push_back(90);
    numbers.push_back(654);

    for (unsigned long i = 0; i < numbers.size(); i++){
        std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
    }

    try {
        easyfind(numbers, 90);
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what();
    }

    return 0;
}