#include <stdio.h>
#include <string.h>

// Note: This C example uses a simplified approach for demonstration purposes.
//       In a real-world scenario, you would use more secure data structures
//       and authentication mechanisms.

int main() {
    char username[50], password[50];
    char stored_username[50] = "user1";
    char stored_password[50] = "password123";

    printf("Username: ");
    scanf("%s", username);

    printf("Password: ");
    scanf("%s", password);

    if (strcmp(username, stored_username) == 0 && strcmp(password, stored_password) == 0) {
        printf("Authentication successful. Welcome, %s!\n", username);
    } else {
        printf("Authentication failed. Invalid username or password.\n");
    }

    return 0;
}