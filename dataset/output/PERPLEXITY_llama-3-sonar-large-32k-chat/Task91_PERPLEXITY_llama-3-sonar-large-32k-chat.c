#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main() {
    int sockfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t clilen;
    char buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket creation failed");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(9876);

    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    while (1) {
        clilen = sizeof(cliaddr);
        recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&cliaddr, &clilen);
        printf("Received packet from %s:%d
", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));
        for (int i = 0; i < BUFFER_SIZE; i++) {
            buffer[i] = toupper(buffer[i]);
        }
        sendto(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&cliaddr, clilen);
    }

    return 0;
}