#include <stdio.h>
#include <string.h>

void accessResource(char resource[]) {
    if (strcmp(resource, "admin") == 0) {
        printf("Access granted to admin resource
");
    } else if (strcmp(resource, "moderator") == 0) {
        printf("Access granted to moderator resource
");
    } else if (strcmp(resource, "user") == 0) {
        printf("Access granted to user resource
");
    } else {
        printf("Access denied
");
    }
}

int main() {
    char resource[20];
    printf("Enter the resource you want to access: ");
    scanf("%19s", resource);
    accessResource(resource);
    return 0;
}