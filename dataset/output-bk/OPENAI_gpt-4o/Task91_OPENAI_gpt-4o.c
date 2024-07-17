#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 5353
#define BUFFER_SIZE 512

void parseQueryName(unsigned char *reader, unsigned char *buffer, char *name) {
    int p = 0, i, j;
    while (*reader != 0) {
        i = *reader;
        for (j = 0; j < i; j++) {
            name[p++] = reader[j + 1];
        }
        name[p++] = '.';
        reader = reader + i + 1;
    }
    name[p - 1] = '\0';
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    unsigned char buffer[BUFFER_SIZE];
    socklen_t addr_len = sizeof(client_addr);

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr));

    while (1) {
        recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&client_addr, &addr_len);

        char query_name[256];
        parseQueryName(buffer + 12, buffer, query_name);

        unsigned char response[BUFFER_SIZE];
        memcpy(response, buffer, 12);
        response[7] = 1; // Answer count

        int offset = 12 + strlen(query_name) + 5;
        memcpy(response + 12, buffer + 12, offset - 12);
        memcpy(response + offset, buffer + 12, strlen(query_name) + 2);
        offset += strlen(query_name) + 2;
        response[offset] = 0x00; response[offset + 1] = 0x01; // Type A
        response[offset + 2] = 0x00; response[offset + 3] = 0x01; // Class IN
        response[offset + 4] = 0x00; response[offset + 5] = 0x00; response[offset + 6] = 0x00; response[offset + 7] = 120; // TTL
        response[offset + 8] = 0x00; response[offset + 9] = 0x04; // Data length
        response[offset + 10] = 127; response[offset + 11] = 0; response[offset + 12] = 0; response[offset + 13] = 1; // 127.0.0.1

        int response_len = offset + 14;
        sendto(sockfd, response, response_len, 0, (struct sockaddr *)&client_addr, addr_len);
    }
    close(sockfd);
    return 0;
}