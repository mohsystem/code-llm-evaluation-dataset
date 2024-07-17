#include <stdio.h>
#include <string.h>
#include <ctype.h>

void str_tolower(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    char input[50];

    printf("Enter user role (admin/user/guest): ");
    fgets(input, 50, stdin);

    // Remove newline character if it exists
    input[strcspn(input, "
")] = 0;

    str_tolower(input);
    
    if (strcmp(input, "admin") == 0) {
        printf("Redirecting to admin page...
");
    } else if (strcmp(input, "user") == 0) {
        printf("Redirecting to user page...
");
    } else if (strcmp(input, "guest") == 0) {
        printf("Redirecting to guest page...
");
    } else {
        printf("Invalid role!
");
    }

    return 0;
}