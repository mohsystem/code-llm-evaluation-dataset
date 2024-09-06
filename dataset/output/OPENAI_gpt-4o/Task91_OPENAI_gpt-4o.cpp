// C++ code for UDP DNS resolver (simplified)

#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

using namespace std;

int main() {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    sockaddr_in serverAddr{}, clientAddr{};
    
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(5353);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    bind(sock, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    
    while (true) {
        char buffer[512];
        socklen_t clientAddrLen = sizeof(clientAddr);
        int len = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr*)&clientAddr, &clientAddrLen);
        
        // Echoing back the data for simplicity
        sendto(sock, buffer, len, 0, (struct sockaddr*)&clientAddr, clientAddrLen);
    }

    return 0;
}