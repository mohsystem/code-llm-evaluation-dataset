
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAX_DNS_SIZE 512
#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 53

struct dns_header {
    uint16_t id;
    uint16_t flags;
    uint16_t qdcount;
    uint16_t ancount;
    uint16_t nscount;
    uint16_t arcount;
};

struct dns_question {
    char* qname;
    uint16_t qtype;
    uint16_t qclass;
};

void parse_dns_query(uint8_t* buffer, struct dns_header* header, struct dns_question* question) {
    memcpy(header, buffer, sizeof(struct dns_header));
    header->id = ntohs(header->id);
    header->flags = ntohs(header->flags);
    header->qdcount = ntohs(header->qdcount);
    header->ancount = ntohs(header->ancount);
    header->nscount = ntohs(header->nscount);
    header->arcount = ntohs(header->arcount);

    int offset = sizeof(struct dns_header);
    int name_length', type='text')