
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 53
#define BUFFER_SIZE 512

void parse_dns_query(unsigned char* query, int length, char* domain_name) {
    int pos = 12; // Skip header
    int i = 0;

    while (pos < length && query[pos] != 0) {
        int label_length = query[pos++];
        for (int j = 0; j < label_length; j++) {
            domain_name[i++] = query[pos++];
        }
        domain_name[i++] = \'.\';
    }
    domain_name[i - 1] = \'\\0\'; // Remove trailing dot
}

void resolve_dns(const char* domain_name, char* ip_address) {
    // Simplified DNS resolution (replace with actual DNS lookup logic)
    strcpy(ip_address, "192.168.1.1");
}

void create_dns_response(unsigned char* query, int query_length, const char* ip_address, unsigned char* response, int* response_length) {
    memcpy(response, query, query_length);
    *response_length = query_length + 16;

    // Set QR bit to 1 (response)
    response[2] |= 0x80;

    // Set Answer count to 1
    response[7] = 1;

    // Add answer section
    int answer_offset = query_length;
    response[answer_offset++] = 0xC0; // Pointer to domain name
    response[answer_offset++] = 12; // Offset to domain name in header

    // Type A record
    response[answer_offset++] = 0;
    response[answer_offset++] = 1;

    // Class IN
    response[answer_offset++] = 0;
    response[answer_offset++] = 1;

    // TTL (4 bytes, set to 300 seconds)
    response[answer_offset++] = 0;
    response[answer_offset++] = 0;
    response[answer_offset++] = 1;
    response[answer_offset++] = 44;

    // Data length (4 bytes for IPv4)
    response[answer_offset++] = 0;
    response[answer_offset++] = 4;

    // IP address
    unsigned char octets[4];
    sscanf(ip_address, "%hhu.%hhu.%hhu.%hhu", &octets[0], &octets[1], &octets[2], &octets[3]);
    memcpy(response + answer_offset, octets, 4);
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    unsigned char buffer[BUFFER_SIZE];
    char domain_name[256];
    char ip_address[16];

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    printf("DNS server listening on port %d\
", PORT);

    while (1) {
        socklen_t client_len = sizeof(client_addr);
        int n = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr*)&client_addr, &client_len);

        if (n < 0) {
            perror("Receive failed");
            continue;
        }

        parse_dns_query(buffer, n, domain_name);
        printf("Received DNS query for: %s\
", domain_name);

        resolve_dns(domain_name, ip_address);

        unsigned char response[BUFFER_SIZE];
        int response_length;
        create_dns_response(buffer, n, ip_address, response, &response_length);

        sendto(sockfd, response, response_length, 0, (struct sockaddr*)&client_addr, client_len);
    }

    close(sockfd);
    return 0;
}
