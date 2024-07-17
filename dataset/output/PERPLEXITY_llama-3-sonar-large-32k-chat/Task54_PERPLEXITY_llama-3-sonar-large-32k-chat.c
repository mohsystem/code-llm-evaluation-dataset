#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int otp = rand() % 900000 + 100000;

    char username[20];
    char password[20];

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    if (strcmp(username, "admin") == 0 && strcmp(password, "password") == 0) {
        printf("One Time Password (OTP) is: %d
", otp);
        int userOtp;
        printf("Enter OTP: ");
        scanf("%d", &userOtp);

        if (userOtp == otp) {
            printf("Login successful!
");
        } else {
            printf("Invalid OTP. Login failed.
");
        }
    } else {
        printf("Invalid username or password. Login failed.
");
    }

    return 0;
}