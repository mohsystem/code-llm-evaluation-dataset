#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define DNS_PORT 53
#define MAX_PACKET_SIZE 512

// Structure to hold DNS header information
struct DNS_HEADER {
    uint16_t id;
    uint16_t flags;
    uint16_t qdcount;
    uint16_t ancount;
    uint16_t nscount;
    uint16_t arcount;
};

// Structure to hold DNS question information
struct DNS_QUESTION {
    char *name;
    uint16_t qtype;
    uint16_t qclass;
};

// Function to convert domain name to DNS format
void change_to_dns_format(char *dns, char *host) {
    int lock = 0;
    strcat(host, ".");

    for (int i = 0; i < strlen(host); i++) {
        if (host[i] == '.') {
            *dns++ = i - lock;
            for (; lock < i; lock++) {
                *dns++ = host[lock];
            }
            lock++;
        }
    }
    *dns++ = '\0';
}

// Function to parse DNS query and extract domain name
char *parse_dns_query(char *buf) {
    struct DNS_HEADER *dns = (struct DNS_HEADER *)buf;
    char *qname = (char *)buf + sizeof(struct DNS_HEADER);
    char *reader = qname;

    // Skip the variable length QNAME field
    while (*reader != 0) {
        reader++;
    }
    reader++;

    // Extract the QTYPE and QCLASS fields
    uint16_t qtype = ntohs(*(uint16_t *)reader);
    reader += sizeof(uint16_t);
    uint16_t qclass = ntohs(*(uint16_t *)reader);
    reader += sizeof(uint16_t);

    // Print the parsed DNS query information
    printf("Query ID: %d
", ntohs(dns->id));
    printf("Question Count: %d
", ntohs(dns->qdcount));
    printf("Answer RRs: %d
", ntohs(dns->ancount));
    printf("Authority RRs: %d
", ntohs(dns->nscount));
    printf("Additional RRs: %d
", ntohs(dns->arcount));
    printf("Domain Name: %s
", qname);
    printf("Query Type: %d
", qtype);
    printf("Query Class: %d
", qclass);

    return qname;
}

// Function to create DNS response packet
char *create_dns_response(char *buf, char *ip_address) {
    struct DNS_HEADER *dns = (struct DNS_HEADER *)buf;
    char *qname = (char *)buf + sizeof(struct DNS_HEADER);
    char *reader = qname;

    // Skip the variable length QNAME field
    while (*reader != 0) {
        reader++;
    }
    reader++;

    // Skip QTYPE and QCLASS fields
    reader += 2 * sizeof(uint16_t);

    // Set response flags in DNS header
    dns->flags = htons(0x8180);
    dns->ancount = htons(1);

    // Copy the query name into the answer section
    char *ans_name = reader;
    strcpy(ans_name, qname);
    reader += strlen(qname) + 1;

    // Set answer type to A (IPv4 address)
    *(uint16_t *)reader = htons(1);
    reader += sizeof(uint16_t);

    // Set answer class to IN (Internet)
    *(uint16_t *)reader = htons(1);
    reader += sizeof(uint16_t);

    // Set answer TTL (arbitrary value)
    *(uint32_t *)reader = htonl(3600);
    reader += sizeof(uint32_t);

    // Set answer data length (IPv4 address length)
    *(uint16_t *)reader = htons(4);
    reader += sizeof(uint16_t);

    // Copy the IP address into the answer section
    struct in_addr addr;
    inet_aton(ip_address, &addr);
    memcpy(reader, &addr, sizeof(addr));
    reader += sizeof(addr);

    return buf;
}

int main() {
    int sockfd;
    char buffer[MAX_PACKET_SIZE];
    char *ip_address = "192.168.1.1"; // Example IP address
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    // Create UDP socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Set server address information
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(DNS_PORT);

    // Bind socket to address
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        close(sockfd);
        exit(1);
    }

    printf("DNS server listening on port %d...
", DNS_PORT);

    while (1) {
        // Receive DNS query from client
        ssize_t recv_len = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&client_addr, &client_len);
        if (recv_len < 0) {
            perror("Error receiving data");
            continue;
        }

        // Parse the DNS query
        char *domain_name = parse_dns_query(buffer);

        // Create DNS response
        char *response = create_dns_response(buffer, ip_address);

        // Send DNS response back to client
        ssize_t send_len = sendto(sockfd, response, reader - buffer, 0, (struct sockaddr *)&client_addr, client_len);
        if (send_len < 0) {
            perror("Error sending data");
        }
    }

    // Close socket (unreachable code)
    close(sockfd);

    return 0;
}