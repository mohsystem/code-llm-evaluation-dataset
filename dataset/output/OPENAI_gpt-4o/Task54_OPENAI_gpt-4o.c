#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateOTP() {
    return 100000 + rand() % 900000;
}

int verifyOTP(int userOTP, int actualOTP) {
    return userOTP == actualOTP;
}

int main() {
    srand(time(NULL));

    char username[50];
    char password[50];
    
    printf("Enter username: ");
    scanf("%s", username);
    
    printf("Enter password: ");
    scanf("%s", password);

    // Simulate verifying username and password
    if (strcmp(username, "user") == 0 && strcmp(password, "pass") == 0) {
        int otp = generateOTP();
        printf("Your OTP is: %d\n", otp);
        int userOTP;
        printf("Enter the OTP you received: ");
        scanf("%d", &userOTP);
        if (verifyOTP(userOTP, otp)) {
            printf("Login successful!\n");
        } else {
            printf("Invalid OTP!\n");
        }
    } else {
        printf("Invalid username or password!\n");
    }

    return 0;
}