#include <iostream>
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 6667
#define BUFFER_SIZE 1024
#define SERVER_PASSWORD "mypassword"

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    char buffer[BUFFER_SIZE] = {0};
    int opt = 1;
    int addrlen = sizeof(address);

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    std::cout << "Server is listening on port " << PORT << std::endl;

    // Accept client connections
    while (true) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
            perror("Accept failed");
            continue;
        }

        std::cout << "New client connected!" << std::endl;

        // Step 2: Handle PASS Command
        ssize_t valread = read(new_socket, buffer, BUFFER_SIZE);
        if (valread > 0) {
            std::string client_message(buffer);
            if (client_message.rfind("PASS ", 0) == 0) { // Check if the message starts with "PASS "
                std::string password = client_message.substr(5); // Extract password
                password.erase(password.find_last_not_of("\r\n") + 1); // Remove newlines

                if (password == SERVER_PASSWORD) {
                    std::string success = "Password accepted\n";
                    send(new_socket, success.c_str(), success.size(), 0);
                    std::cout << "Client authenticated successfully." << std::endl;
                } else {
                    std::string fail = "Invalid password\n";
                    send(new_socket, fail.c_str(), fail.size(), 0);
                    close(new_socket);
                    std::cout << "Client disconnected due to invalid password." << std::endl;
                }
            } else {
                std::string error = "Expected PASS command\n";
                send(new_socket, error.c_str(), error.size(), 0);
                close(new_socket);
                std::cout << "Client disconnected for incorrect command." << std::endl;
            }
        }
        memset(buffer, 0, BUFFER_SIZE); // Clear the buffer
    }

    return 0;
}
