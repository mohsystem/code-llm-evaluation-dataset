#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/sha.h>

#define MAX_USERNAME_LEN 100
#define MAX_PASSWORD_LEN 100
#define HASH_LEN (SHA256_DIGEST_LENGTH * 2 + 1)

void hash_password(const char *password, char *hashed_password) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, password, strlen(password));
    SHA256_Final(hash, &sha256);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(hashed_password + (i * 2), "%02x", hash[i]);
    }
}

void create_user(const char *username, const char *password) {
    FILE *fp = fopen("users.txt", "a");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file for writing.\n");
        return;
    }
    char hashed_password[HASH_LEN];
    hash_password(password, hashed_password);
    fprintf(fp, "%s:%s\n", username, hashed_password);
    fclose(fp);
    printf("User '%s' created successfully!\n", username);
}

int authenticate_user(const char *username, const char *password) {
    FILE *fp = fopen("users.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file for reading.\n");
        return 0;
    }
    char line[MAX_USERNAME_LEN + MAX_PASSWORD_LEN + 2]; // +2 for ':' and '\n'
    char stored_username[MAX_USERNAME_LEN];
    char stored_hash[HASH_LEN];
    char input_hash[HASH_LEN];
    hash_password(password, input_hash);

    while (fgets(line, sizeof(line), fp) != NULL) {
        if (sscanf(line, "%[^:]:%s\n", stored_username, stored_hash) == 2 && 
            strcmp(username, stored_username) == 0 &&
            strcmp(input_hash, stored_hash) == 0) {
            fclose(fp);
            printf("Authentication successful. Welcome!\n");
            return 1;
        }
    }
    fclose(fp);
    printf("Authentication failed. Invalid username or password.\n");
    return 0;
}

int main() {
    int choice;
    char username[MAX_USERNAME_LEN];
    char password[MAX_PASSWORD_LEN];

    while (1) {
        printf("1. Create user\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                printf("Enter username: ");
                fgets(username, sizeof(username), stdin);
                username[strcspn(username, "\n")] = 0; // Remove trailing newline
                printf("Enter password: ");
                fgets(password, sizeof(password), stdin);
                password[strcspn(password, "\n")] = 0; // Remove trailing newline
                create_user(username, password);
                break;
            case 2:
                printf("Enter username: ");
                fgets(username, sizeof(username), stdin);
                username[strcspn(username, "\n")] = 0; // Remove trailing newline
                printf("Enter password: ");
                fgets(password, sizeof(password), stdin);
                password[strcspn(password, "\n")] = 0; // Remove trailing newline
                authenticate_user(username, password);
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}