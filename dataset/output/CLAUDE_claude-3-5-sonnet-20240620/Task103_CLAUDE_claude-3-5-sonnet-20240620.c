
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int checkPasswordStrength(const char* password) {
    int length = strlen(password);
    int hasUpper = 0, hasLower = 0, hasDigit = 0;
    
    if (length < 8) {
        return 0;
    }
    
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            hasUpper = 1;
        } else if (islower(password[i])) {
            hasLower = 1;
        } else if (isdigit(password[i])) {
            hasDigit = 1;
        }
    }
    
    return hasUpper && hasLower && hasDigit;
}

int main() {
    char password[100];
    printf("Enter a password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\\n")] = 0; // Remove newline
    
    if (checkPasswordStrength(password)) {
        printf("Password is strong\\n");
    } else {
        printf("Password is weak\\n");
    }
    
    return 0;
}
