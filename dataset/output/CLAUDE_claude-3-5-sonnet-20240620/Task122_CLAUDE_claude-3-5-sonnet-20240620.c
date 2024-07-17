
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/sha.h>

#define MAX_USERS 100
#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50

struct User {
    char username[MAX_USERNAME_LENGTH];
    char password[SHA256_DIGEST_LENGTH * 2 + 1];
};

struct User users[MAX_USERS];
int user_count = 0;

void sha256(char *string, char outputBuffer[65]) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, string, strlen(string));
    SHA256_Final(hash, &sha256);
    int i;
    for(i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(outputBuffer + (i * 2), "%02x", hash[i]);
    }
    outputBuffer[64] = 0;
}

void signup() {
    if (user_count >= MAX_USERS) {
        printf("Maximum number of users reached.\
");
        return;
    }

    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    strcpy(users[user_count].username, username);
    sha256(password, users[user_count].password);

    user_count++;
    printf("Signup successful!\
");
}

int main() {
    char choice;
    do {
        signup();
        printf("Do you want to add another user? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == \'y\' || choice == \'Y\');

    printf("Final password dictionary:\
");
    for (int i = 0; i < user_count; i++) {
        printf("%s: %s\
", users[i].username, users[i].password);
    }

    return 0;
}
