#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Note: Sending emails from C requires external libraries.
//       This example focuses on OTP generation and verification.

char* generateOTP(int length) {
    char *otp = malloc((length + 1) * sizeof(char)); // Allocate memory for OTP
    if (otp == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1); // Exit with an error code
    }

    const char digits[] = "0123456789";
    srand(time(NULL));

    for (int i = 0; i < length; i++) {
        otp[i] = digits[rand() % 10];
    }
    otp[length] = '\0'; // Add null terminator to make it a string
    return otp;
}

int main() {
    char username[50], password[50], enteredOTP[7]; // Assuming max username/password length of 50

    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    // Simulate user authentication (replace with your actual authentication logic)
    if (strcmp(username, "user") == 0 && strcmp(password, "password") == 0) {
        char* otp = generateOTP(6);
        printf("OTP: %s\n", otp); // Displaying for demo purposes (send via email in reality)

        printf("Enter OTP: ");
        scanf("%6s", enteredOTP); // Read up to 6 characters to prevent buffer overflow

        if (strcmp(enteredOTP, otp) == 0) {
            printf("Two-factor authentication successful. Logged in!\n");
        } else {
            printf("Incorrect OTP. Access denied.\n");
        }
        free(otp); // Free dynamically allocated memory
    } else {
        printf("Invalid username or password.\n");
    }

    return 0;
}