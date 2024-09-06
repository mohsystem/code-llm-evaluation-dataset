#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

void signup() {
    char username[100], password[100];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, password, strlen(password));
    SHA256_Final(hash, &sha256);

    char hashedPassword[SHA256_DIGEST_LENGTH * 2 + 1];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(&hashedPassword[i * 2], "%02x", hash[i]);
    }

    FILE *file = fopen("users.txt", "a");
    if (file != NULL) {
        fprintf(file, "%s:%s\n", username, hashedPassword);
        fclose(file);
        printf("Signup successful!\n");
    } else {
        fprintf(stderr, "Unable to open file.\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("1. Signup\n");
        printf("2. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            signup();
        } else if (choice == 2) {
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}