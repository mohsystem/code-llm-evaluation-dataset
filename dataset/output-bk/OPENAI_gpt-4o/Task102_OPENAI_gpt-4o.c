#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

void hashPassword(const char* password, char* hashedPassword) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, password, strlen(password));
    SHA256_Final(hash, &sha256);

    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(hashedPassword + (i * 2), "%02x", hash[i]);
    }
}

void updatePasswordInDatabase(const char* username, const char* hashedPassword) {
    printf("Updating password for user: %s
", username);
    // Database interaction code would go here
}

int main() {
    char username[50];
    char password[50];
    char hashedPassword[65] = {0};

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter new password: ");
    scanf("%s", password);

    hashPassword(password, hashedPassword);
    updatePasswordInDatabase(username, hashedPassword);

    return 0;
}