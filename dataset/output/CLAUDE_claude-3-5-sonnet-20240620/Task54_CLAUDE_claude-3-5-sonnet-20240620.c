
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_USERS 10
#define MAX_LENGTH 20

struct User {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
};

struct User users[MAX_USERS];
int user_count = 0;

char otp[7];

void generate_otp() {
    srand(time(NULL));
    sprintf(otp, "%06d", rand() % 1000000);
}

int main() {
    char username[MAX_LENGTH], password[MAX_LENGTH], entered_otp[7];

    // Register a user
    printf("Register - Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    strcpy(users[user_count].username, username);
    strcpy(users[user_count].password, password);
    user_count++;

    // Login
    printf("Login - Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    int found = 0;
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        generate_otp();
        printf("OTP sent: %s\
", otp);

        printf("Enter OTP: ");
        scanf("%s", entered_otp);

        if (strcmp(otp, entered_otp) == 0) {
            printf("Login successful!\
");
        } else {
            printf("Invalid OTP. Login failed.\
");
        }
    } else {
        printf("Invalid username or password.\
");
    }

    return 0;
}
