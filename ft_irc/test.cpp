#include <iostream>
#include <string>
#include <cstring>
#include <sys/socket.h> //socket() is defined here
#include <netinet/in.h>
#include <unistd.h>

#define PORT 6667
#define BUFFER_SIZE 1024
#define SERVER_PASSWORD "00123"

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address; // like server card this data type used to store our socket address && port ...
    char buffer[BUFFER_SIZE] = {0};
    int opt = 1;
    int addrlen = sizeof(address);

    // Create Socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) { // AF_INET     : specifying network type to IPV4
        perror("socket failed");                              // SOCK_STREAM : set communication type to TCP (we've created a stream scokets(other socket type is datagram socked which use UDP))
        exit (EXIT_FAILURE);
    }

    // Bind de socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        close (server_fd);
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr   = INADDR_ANY; // make it listen to any address
    address.sin_port   = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close (server_fd);
        exit (EXIT_FAILURE);
    }

    // Listen for connection
    if (listen(server_fd, 3) < 0) { // 3 the maximum number of pending connection in que
        perror ("Listen failed");
        close (server_fd);
        exit(EXIT_FAILURE);
    }
    std::cout << "My f* Server is listening on port " << PORT << std::endl;

    // Accept Client Connections
    while (true) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) { //&address pointer to sockaddr where the client addr will be stored
            perror("Accept Failed");
            continue ;
        }
        // step 2 : Handle PASS Command
        std::cout << "New client connected!" << std::endl;
        ssize_t valread = read(new_socket, buffer, BUFFER_SIZE);
        if (valread > 0) {
            std::cout << "reading ...." << std::endl;
            std::string client_message(buffer);
            if (client_message.rfind("PASS ", 0) == 0) //checking if PASS command has been entered
            {
                std::string password = client_message.substr(5); // Extract password
                password.erase(password.find_last_not_of("\r\n") + 1); // Remove newline
                if (password == SERVER_PASSWORD) {
                    std::string success = "Password accepted\n";
                    send(new_socket, success.c_str(), success.size(), 0);
                    std::cout << "Client Authenticated successfully" << std::endl;
                }
                else
                    close (new_socket);
            }
            else
            {
                std::string failed = "Command not exist";
                send(new_socket, failed.c_str(), failed.size(), 0);
                close (new_socket);
            }
        }
    }
}