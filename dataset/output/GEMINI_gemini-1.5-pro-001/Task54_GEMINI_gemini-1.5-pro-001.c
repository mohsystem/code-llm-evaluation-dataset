#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char username[50], password[50];
    int otp, enteredOtp;

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    // Simulated user authentication
    if (authenticate(username, password)) {
        otp = generateOTP();
        printf("One-Time Password: %d
", otp);

        printf("Enter OTP: ");
        scanf("%d", &enteredOtp);

        if (enteredOtp == otp) {
            printf("Two-factor authentication successful. Access granted!
");
        } else {
            printf("Incorrect OTP. Access denied!
");
        }
    } else {
        printf("Invalid username or password. Access denied!
");
    }

    return 0;
}

// Simulated authentication function (replace with actual database check)
int authenticate(const char* username, const char* password) {
    return (strcmp(username, "user") == 0 && strcmp(password, "password") == 0);
}

// Generate a random 6-digit OTP
int generateOTP() {
    srand(time(NULL));
    return 100000 + rand() % 900000;
}