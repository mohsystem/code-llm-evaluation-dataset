// C code for UDP DNS resolver (simplified)

#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in serverAddr, clientAddr;
    
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(5353);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    bind(sock, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    
    while (1) {
        char buffer[512];
        socklen_t clientAddrLen = sizeof(clientAddr);
        int len = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr*)&clientAddr, &clientAddrLen);
        
        // Echoing back the data for simplicity
        sendto(sock, buffer, len, 0, (struct sockaddr*)&clientAddr, clientAddrLen);
    }

    return 0;
}