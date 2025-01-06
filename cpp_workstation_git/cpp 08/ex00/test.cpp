#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers;

    // Add elements to the vector
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    // Access and display elements
    std::cout << "First element: " << numbers[0] << std::endl;

    // Iterate through the vector
    int i = 0;
    while (i < numbers.size()) {
        std::cout << "Element " << i << ": " << numbers[i] << std::endl;
        i++;
    }

    std::cout << "before pop_back, size: " << numbers.size() << std::endl;
    // Remove the last element
    numbers.pop_back();

    std::cout << "After pop_back, size: " << numbers.size() << std::endl;
    return 0;
}
