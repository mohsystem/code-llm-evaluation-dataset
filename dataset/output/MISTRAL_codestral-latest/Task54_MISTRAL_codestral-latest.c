#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

const char CHARACTERS[] = "0123456789";
const int OTP_LENGTH = 6;

char* generate_otp() {
    char* otp = malloc(OTP_LENGTH + 1);
    for (int i = 0; i < OTP_LENGTH; i++) {
        otp[i] = CHARACTERS[rand() % strlen(CHARACTERS)];
    }
    otp[OTP_LENGTH] = '\0';
    return otp;
}

char* login(const char* username, const char* password, const char* otp) {
    // Here you would normally check the username and password against a database
    // For this example, we'll just assume they're correct
    if (strcmp(username, "user") == 0 && strcmp(password, "password") == 0) {
        char* generated_otp = generate_otp();
        if (strcmp(otp, generated_otp) == 0) {
            free(generated_otp);
            return "Login successful";
        } else {
            free(generated_otp);
            return "Invalid OTP";
        }
    } else {
        return "Invalid username or password";
    }
}

// Example usage:
int main() {
    srand(time(0));
    char* otp = generate_otp();
    printf("%s\n", login("user", "password", otp));
    free(otp);
    return 0;
}