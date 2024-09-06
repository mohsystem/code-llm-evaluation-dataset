#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        fprintf(stderr, "Error creating socket\n");
        return 1;
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(53);
    inet_pton(AF_INET, "127.0.0.1", &(server_address.sin_addr));

    if (bind(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        fprintf(stderr, "Error binding socket\n");
        return 1;
    }

    printf("Starting UDP server on localhost port 53\n");

    while (true) {
        char buffer[4096];
        struct sockaddr_in client_address;
        socklen_t client_len = sizeof(client_address);
        int bytes_received = recvfrom(sock, buffer, 4096, 0, (struct sockaddr *)&client_address, &client_len);
        if (bytes_received < 0) {
            fprintf(stderr, "Error receiving data\n");
            return 1;
        }

        // Parse the received data (DNS request)
        // This is a simplified example, in real-world scenarios you would need to parse the DNS request using a library
        printf("Received %d bytes from %s\n", bytes_received, inet_ntoa(client_address.sin_addr));
        printf("%s\n", buffer);

        // Resolve DNS records (this is a simplified example, in real-world scenarios you would need to use a DNS resolver library)
        char dns_response[] = "DNS response";

        // Send the response back to the client
        int bytes_sent = sendto(sock, dns_response, strlen(dns_response), 0, (struct sockaddr *)&client_address, client_len);
        if (bytes_sent < 0) {
            fprintf(stderr, "Error sending data\n");
            return 1;
        }

        printf("Sent %d bytes back to %s\n", bytes_sent, inet_ntoa(client_address.sin_addr));
    }

    return 0;
}