#include <iostream>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        std::cerr << "Error creating socket" << std::endl;
        return 1;
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(53);
    inet_pton(AF_INET, "127.0.0.1", &(server_address.sin_addr));

    if (bind(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        std::cerr << "Error binding socket" << std::endl;
        return 1;
    }

    std::cout << "Starting UDP server on localhost port 53" << std::endl;

    while (true) {
        char buffer[4096];
        struct sockaddr_in client_address;
        socklen_t client_len = sizeof(client_address);
        int bytes_received = recvfrom(sock, buffer, 4096, 0, (struct sockaddr *)&client_address, &client_len);
        if (bytes_received < 0) {
            std::cerr << "Error receiving data" << std::endl;
            return 1;
        }

        // Parse the received data (DNS request)
        // This is a simplified example, in real-world scenarios you would need to parse the DNS request using a library
        std::cout << "Received " << bytes_received << " bytes from " << inet_ntoa(client_address.sin_addr) << std::endl;
        std::cout << buffer << std::endl;

        // Resolve DNS records (this is a simplified example, in real-world scenarios you would need to use a DNS resolver library)
        std::string dns_response = "DNS response";

        // Send the response back to the client
        int bytes_sent = sendto(sock, dns_response.c_str(), dns_response.size(), 0, (struct sockaddr *)&client_address, client_len);
        if (bytes_sent < 0) {
            std::cerr << "Error sending data" << std::endl;
            return 1;
        }

        std::cout << "Sent " << bytes_sent << " bytes back to " << inet_ntoa(client_address.sin_addr) << std::endl;
    }

    return 0;
}