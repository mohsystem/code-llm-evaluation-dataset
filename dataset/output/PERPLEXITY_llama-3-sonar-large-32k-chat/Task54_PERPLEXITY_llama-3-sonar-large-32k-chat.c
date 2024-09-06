#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* generateOTP() {
    static char otp[7];
    srand(time(0));
    sprintf(otp, "%06d", rand() % 900000 + 100000);
    return otp;
}

char* authenticate(char* username, char* password, char* otp) {
    if (strcmp(username, "admin") == 0 && strcmp(password, "password") == 0 && strcmp(otp, generateOTP()) == 0) {
        return "Authentication successful";
    } else {
        return "Authentication failed";
    }
}

int main() {
    char username[100], password[100], otp[100];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    printf("Enter OTP: ");
    scanf("%s", otp);
    printf("%s\n", authenticate(username, password, otp));
    return 0;
}