#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char username[] = "user";
    char password[] = "password";
    char inputUsername[100], inputPassword[100];
    int otp, inputOTP;

    printf("Enter username:
");
    scanf("%s", inputUsername);
    printf("Enter password:
");
    scanf("%s", inputPassword);

    if (strcmp(username, inputUsername) == 0 && strcmp(password, inputPassword) == 0) {
        // Generate OTP
        srand(time(0));
        otp = rand() % 1000000;
        printf("Generated OTP: %06d
", otp);
        printf("Enter OTP:
");
        scanf("%d", &inputOTP);

        if (inputOTP == otp) {
            printf("Login Successful
");
        } else {
            printf("Invalid OTP
");
        }
    } else {
        printf("Invalid username or password
");
    }

    return 0;
}