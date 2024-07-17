#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    char hostname[256], username[256], password[256], filename[256];
    strcpy(hostname, argv[1]);
    strcpy(username, argv[2]);
    strcpy(password, argv[3]);
    strcpy(filename, argv[4]);

    int sockfd, connfd;
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket creation failed");
        exit(1);
    }

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(21);
    inet_pton(AF_INET, hostname, &(servaddr.sin_addr));

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connection failed");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    char cmd[256];
    sprintf(cmd, "USER %s\r
", username);
    send(sockfd, cmd, strlen(cmd), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    sprintf(cmd, "PASS %s\r
", password);
    send(sockfd, cmd, strlen(cmd), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    sprintf(cmd, "RETR %s\r
", filename);
    send(sockfd, cmd, strlen(cmd), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("file open failed");
        exit(1);
    }

    while (recv(sockfd, buffer, BUFFER_SIZE, 0) > 0) {
        fwrite(buffer, 1, strlen(buffer), fp);
    }

    fclose(fp);
    close(sockfd);

    return 0;
}