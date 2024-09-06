#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <openssl/sha.h>

char* generateToken(const char* username, const char* password) {
    char timestamp[20];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    strftime(timestamp, sizeof(timestamp), "%Y%m%d%H%M%S", &tm);
    char data[256];
    sprintf(data, "%s%s%s", username, password, timestamp);
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data, strlen(data));
    SHA256_Final(hash, &sha256);
    char* token = malloc(SHA256_DIGEST_LENGTH * 2 + 1);
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(token + (i * 2), "%02x", hash[i]);
    }
    return token;
}