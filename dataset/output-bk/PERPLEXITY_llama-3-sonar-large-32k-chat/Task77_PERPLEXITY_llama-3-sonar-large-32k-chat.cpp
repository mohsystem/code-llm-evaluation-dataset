#include <iostream>
#include <string>
#include <fstream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    std::string hostname = argv[1];
    std::string username = argv[2];
    std::string password = argv[3];
    std::string filename = argv[4];

    int sockfd, connfd;
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        std::cerr << "socket creation failed" << std::endl;
        exit(1);
    }

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(21);
    inet_pton(AF_INET, hostname.c_str(), &(servaddr.sin_addr));

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        std::cerr << "connection failed" << std::endl;
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    std::cout << buffer << std::endl;

    std::string cmd;
    cmd = "USER " + username + "\r
";
    send(sockfd, cmd.c_str(), cmd.length(), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    std::cout << buffer << std::endl;

    cmd = "PASS " + password + "\r
";
    send(sockfd, cmd.c_str(), cmd.length(), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    std::cout << buffer << std::endl;

    cmd = "RETR " + filename + "\r
";
    send(sockfd, cmd.c_str(), cmd.length(), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    std::cout << buffer << std::endl;

    std::ofstream fp(filename, std::ios::binary);
    if (!fp) {
        std::cerr << "file open failed" << std::endl;
        exit(1);
    }

    while (recv(sockfd, buffer, BUFFER_SIZE, 0) > 0) {
        fp.write(buffer, strlen(buffer));
    }

    fp.close();
    close(sockfd);

    return 0;
}