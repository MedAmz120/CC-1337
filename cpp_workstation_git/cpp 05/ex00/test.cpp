#include <iostream>
#include <stdexcept>  // To handle errors

int main() {
    int cookies = 5;
    int friends = 0;

    try {
        if (friends == 0) {
            throw std::runtime_error("You can't divide by zero!");  // Uh-oh, problem!
        }
        std::cout << "Each friend gets " << cookies / friends << " cookies." << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;  // This prints the error message
    }

    return 0;
}