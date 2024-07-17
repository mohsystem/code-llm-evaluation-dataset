#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

int main() {
    char cert[] = "sample_certificate"; // Replace with actual SSL certificate content
    char knownHash[] = "known_hash"; // Replace with actual known hash
    
    unsigned char digest[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char*)&cert, strlen(cert), (unsigned char*)&digest);

    char mdString[SHA256_DIGEST_LENGTH*2+1];
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
        sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);
    
    if (strcmp(mdString, knownHash) == 0) {
        printf("C: Certificate matches the known hash.
");
    } else {
        printf("C: Certificate does not match the known hash.
");
    }
    
    return 0;
}