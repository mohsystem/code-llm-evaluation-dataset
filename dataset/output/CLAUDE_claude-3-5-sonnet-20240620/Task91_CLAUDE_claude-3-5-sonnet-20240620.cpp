
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

const int PORT = 53;
const int BUFFER_SIZE = 512;

void parseDNSQuery(unsigned char* query, int length, std::string& domainName) {
    int pos = 12; // Skip header
    while (pos < length && query[pos] != 0) {
        int labelLength = query[pos++];
        for (int i = 0; i < labelLength; i++) {
            domainName += query[pos++];
        }
        domainName += \'.\';
    }
    if (!domainName.empty()) {
        domainName.pop_back(); // Remove trailing dot
    }
}

std::string resolveDNS(const std::string& domainName) {
    // Simplified DNS resolution (replace with actual DNS lookup logic)
    return "192.168.1.1";
}

void createDNSResponse(unsigned char* query, int queryLength, const std::string& ipAddress, unsigned char* response, int& responseLength) {
    std::memcpy(response, query, queryLength);
    responseLength = queryLength + 16;

    // Set QR bit to 1 (response)
    response[2] |= 0x80;

    // Set Answer count to 1
    response[7] = 1;

    // Add answer section
    int answerOffset = queryLength;
    response[answerOffset++] = 0xC0; // Pointer to domain name
    response[answerOffset++] = 12; // Offset to domain name in header

    // Type A record
    response[answerOffset++] = 0;
    response[answerOffset++] = 1;

    // Class IN
    response[answerOffset++] = 0;
    response[answerOffset++] = 1;

    // TTL (4 bytes, set to 300 seconds)
    response[answerOffset++] = 0;
    response[answerOffset++] = 0;
    response[answerOffset++] = 1;
    response[answerOffset++] = 44;

    // Data length (4 bytes for IPv4)
    response[answerOffset++] = 0;
    response[answerOffset++] = 4;

    // IP address
    unsigned char octets[4];
    sscanf(ipAddress.c_str(), "%hhu.%hhu.%hhu.%hhu", &octets[0], &octets[1], &octets[2], &octets[3]);
    std::memcpy(response + answerOffset, octets, 4);
}

int main() {
    int sockfd;
    struct sockaddr_in serverAddr, clientAddr;
    unsigned char buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        std::cerr << "Socket creation failed" << std::endl;
        return 1;
    }

    std::memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        std::cerr << "Bind failed" << std::endl;
        return 1;
    }

    std::cout << "DNS server listening on port " << PORT << std::endl;

    while (true) {
        socklen_t clientLen = sizeof(clientAddr);
        int n = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr*)&clientAddr, &clientLen);

        if (n < 0) {
            std::cerr << "Receive failed" << std::endl;
            continue;
        }

        std::string domainName;
        parseDNSQuery(buffer, n, domainName);
        std::cout << "Received DNS query for: " << domainName << std::endl;

        std::string ipAddress = resolveDNS(domainName);

        unsigned char response[BUFFER_SIZE];
        int responseLength;
        createDNSResponse(buffer, n, ipAddress, response, responseLength);

        sendto(sockfd, response, responseLength, 0, (struct sockaddr*)&clientAddr, clientLen);
    }

    close(sockfd);
    return 0;
}
