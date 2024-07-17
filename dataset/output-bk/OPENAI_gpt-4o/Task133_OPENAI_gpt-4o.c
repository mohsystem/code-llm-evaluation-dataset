#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

void hashPassword(const char* password, unsigned char* digest) {
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, password, strlen(password));
    SHA256_Final(digest, &sha256);
}

void printHash(unsigned char* hash) {
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("
");
}

int main() {
    char currentPassword[256];
    char newPassword[256];
    
    unsigned char currentHash[SHA256_DIGEST_LENGTH];
    unsigned char newHash[SHA256_DIGEST_LENGTH];
    
    printf("C: Enter your current password:
");
    fgets(currentPassword, sizeof(currentPassword), stdin);
    currentPassword[strcspn(currentPassword, "
")] = 0;  // Remove newline character
    hashPassword(currentPassword, currentHash);
    
    printf("C: Enter new password:
");
    fgets(newPassword, sizeof(newPassword), stdin);
    newPassword[strcspn(newPassword, "
")] = 0;  // Remove newline character
    hashPassword(newPassword, newHash);

    printf("C: Password has been reset!
");

    return 0;
}