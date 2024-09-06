#include <stdio.h>
#include <string.h>

void accessResource(char resource[]) {
    if (strcmp(resource, "admin") == 0) {
        printf("Access granted to admin resource\n");
    } else if (strcmp(resource, "moderator") == 0) {
        printf("Access granted to moderator resource\n");
    } else if (strcmp(resource, "user") == 0) {
        printf("Access granted to user resource\n");
    } else {
        printf("Access denied\n");
    }
}

int main() {
    char resource[20];
    printf("Enter the resource you want to access: ");
    scanf("%19s", resource);
    accessResource(resource);
    return 0;
}