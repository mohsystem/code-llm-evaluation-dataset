
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define OTP_LENGTH 6

char* generateOTP() {
    static char otp[OTP_LENGTH + 1];
    const char digits[] = "0123456789";
    
    srand(time(NULL));
    for (int i = 0; i < OTP_LENGTH; i++) {
        otp[i] = digits[rand() % 10];
    }
    otp[OTP_LENGTH] = '\\0';
    
    return otp;
}

void sendOTP(const char* otp) {
    printf("OTP sent: %s\\n", otp);
}

int verifyOTP(const char* userOTP, const char* generatedOTP) {
    return strcmp(userOTP, generatedOTP) == 0;
}

void login() {
    char username[50], password[50];
    
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    
    if (strcmp(username, "user") == 0 && strcmp(password, "password") == 0) {
        char* otp = generateOTP();
        sendOTP(otp);
        
        char userOTP[OTP_LENGTH + 1];
        printf("Enter OTP: ");
        scanf("%s", userOTP);
        
        if (verifyOTP(userOTP, otp)) {
            printf("Login successful!\\n");
        } else {
            printf("Invalid OTP. Login failed.\\n");
        }
    } else {
        printf("Invalid username or password.\\n");
    }
}

int main() {
    login();
    return 0;
}
