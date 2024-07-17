#include <iostream>
#include <string>
#include <unordered_map>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

#define DNS_PORT 53
#define MAX_PACKET_SIZE 512

// Structure to represent a DNS header
struct DNSHeader {
    uint16_t id;
    uint16_t flags;
    uint16_t qdcount;
    uint16_t ancount;
    uint16_t nscount;
    uint16_t arcount;
};

// Structure to represent a DNS question
struct DNSQuestion {
    std::string qname;
    uint16_t qtype;
    uint16_t qclass;
};

// Function to convert domain name to DNS format
void toDNSFormat(std::string& domainName) {
    size_t pos = 0;
    while ((pos = domainName.find('.', pos)) != std::string::npos) {
        domainName.insert(pos, 1, domainName.at(pos - 1));
        pos += 2;
    }
}

// Function to extract the domain name from a DNS query
std::string extractDomainName(const char* buffer, int& index) {
    std::string domainName;
    while (buffer[index] != '\0') {
        int labelLength = static_cast<int>(buffer[index]);
        index++;
        domainName += std::string(buffer + index, labelLength) + '.';
        index += labelLength;
    }
    index++; // Skip the null terminator
    domainName.pop_back(); // Remove the trailing dot
    return domainName;
}

// Function to parse a DNS query
DNSQuestion parseDNSQuery(const char* buffer) {
    DNSQuestion dnsQuestion;
    int index = sizeof(DNSHeader);

    // Extract the domain name from the query
    dnsQuestion.qname = extractDomainName(buffer, index);

    // Extract the query type and class
    dnsQuestion.qtype = ntohs(*reinterpret_cast<const uint16_t*>(buffer + index));
    index += sizeof(uint16_t);
    dnsQuestion.qclass = ntohs(*reinterpret_cast<const uint16_t*>(buffer + index));

    return dnsQuestion;
}

// Function to create a DNS response
void createDNSResponse(char* buffer, const std::string& ipAddress) {
    // Parse the DNS query
    DNSQuestion dnsQuestion = parseDNSQuery(buffer);

    // Modify the DNS header
    DNSHeader* dnsHeader = reinterpret_cast<DNSHeader*>(buffer);
    dnsHeader->flags = htons(0x8180); // Set response flags
    dnsHeader->ancount = htons(1);    // Set answer count to 1

    // Modify the DNS answer section
    int index = sizeof(DNSHeader) + dnsQuestion.qname.size() + 2 + 4; // Position after the question section

    // Copy the domain name to the answer section
    std::strcpy(buffer + index, dnsQuestion.qname.c_str());
    index += dnsQuestion.qname.size() + 1;

    // Set answer type to A (IPv4 address)
    *reinterpret_cast<uint16_t*>(buffer + index) = htons(1);
    index += sizeof(uint16_t);

    // Set answer class to IN (Internet)
    *reinterpret_cast<uint16_t*>(buffer + index) = htons(1);
    index += sizeof(uint16_t);

    // Set answer TTL (arbitrary value)
    *reinterpret_cast<uint32_t*>(buffer + index) = htonl(3600);
    index += sizeof(uint32_t);

    // Set answer data length (IPv4 address length)
    *reinterpret_cast<uint16_t*>(buffer + index) = htons(4);
    index += sizeof(uint16_t);

    // Copy the IP address to the answer section
    inet_pton(AF_INET, ipAddress.c_str(), buffer + index);
}

int main() {
    // Create a UDP socket
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        std::cerr << "Failed to create socket" << std::endl;
        return 1;
    }

    // Bind the socket to the DNS port
    sockaddr_in serverAddress{};
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(DNS_PORT);
    if (bind(sockfd, reinterpret_cast<sockaddr*>(&serverAddress), sizeof(serverAddress)) < 0) {
        std::cerr << "Failed to bind socket" << std::endl;
        close(sockfd);
        return 1;
    }

    std::cout << "DNS server listening on port " << DNS_PORT << std::endl;

    // Create a map to store DNS records
    std::unordered_map<std::string, std::string> dnsRecords = {
        {"google.com", "172.217.160.142"},
        {"facebook.com", "157.240.195.35"}
        // Add more DNS records as needed
    };

    while (true) {
        char buffer[MAX_PACKET_SIZE];
        sockaddr_in clientAddress{};
        socklen_t clientAddressLength = sizeof(clientAddress);

        // Receive a DNS query from a client
        ssize_t bytesReceived = recvfrom(sockfd, buffer, sizeof(buffer), 0, reinterpret_cast<sockaddr*>(&clientAddress), &clientAddressLength);
        if (bytesReceived < 0) {
            std::cerr << "Failed to receive data" << std::endl;
            continue;
        }

        // Parse the DNS query and extract the domain name
        DNSQuestion dnsQuestion = parseDNSQuery(buffer);
        std::string domainName = dnsQuestion.qname;
        std::cout << "Received DNS query for: " << domainName << std::endl;

        // Resolve the domain name to an IP address
        std::string ipAddress = dnsRecords[domainName];

        // Create a DNS response
        createDNSResponse(buffer, ipAddress);

        // Send the DNS response back to the client
        ssize_t bytesSent = sendto(sockfd, buffer, bytesReceived, 0, reinterpret_cast<sockaddr*>(&clientAddress), clientAddressLength);
        if (bytesSent < 0) {
            std::cerr << "Failed to send data" << std::endl;
        }
    }

    // Close the socket
    close(sockfd);

    return 0;
}