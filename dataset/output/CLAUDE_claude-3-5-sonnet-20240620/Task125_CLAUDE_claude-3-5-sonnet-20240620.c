
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 50

bool authenticate() {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    return (strcmp(username, "admin") == 0 && strcmp(password, "password123") == 0);
}

void access_resource(const char* resource) {
    if (strcmp(resource, "1") == 0) {
        printf("Accessing confidential files...\\n");
    } else if (strcmp(resource, "2") == 0) {
        printf("Accessing financial records...\\n");
    } else if (strcmp(resource, "3") == 0) {
        printf("Accessing employee database...\\n");
    } else {
        printf("Invalid resource selection.\\n");
    }
}

int main() {
    if (authenticate()) {
        printf("Authentication successful.\\n");
        char choice[MAX_LENGTH];
        while (1) {
            printf("\\nAvailable resources:\\n");
            printf("1. Confidential files\\n");
            printf("2. Financial records\\n");
            printf("3. Employee database\\n");
            printf("4. Exit\\n");
            printf("Enter resource number to access (or 4 to exit): ");
            scanf("%s", choice);
            if (strcmp(choice, "4") == 0) {
                break;
            }
            access_resource(choice);
        }
    } else {
        printf("Authentication failed. Access denied.\\n");
    }
    return 0;
}
