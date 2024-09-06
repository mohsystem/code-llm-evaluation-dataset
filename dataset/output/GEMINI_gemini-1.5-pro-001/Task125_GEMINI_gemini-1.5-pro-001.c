#include <stdio.h>
#include <string.h>

// Define a simple structure to represent a resource
struct Resource {
    char name[50];
};

// Define a structure to represent a role with an array of resources
struct Role {
    char name[50];
    struct Resource resources[3];
    int resourceCount; 
};

int main() {
    // Define the resources
    struct Resource resource1 = {"resource1"};
    struct Resource resource2 = {"resource2"};
    struct Resource resource3 = {"resource3"};

    // Define the roles and their associated resources
    struct Role roles[3] = {
        {"admin", {resource1, resource2, resource3}, 3},
        {"editor", {resource2, resource3}, 2},
        {"viewer", {resource3}, 1}
    };

    char userRole[50];
    printf("Enter your role (admin, editor, viewer): ");
    scanf("%s", userRole);

    int i, j;
    int roleFound = 0; // Flag to track if the role is found

    for (i = 0; i < 3; i++) {
        if (strcmp(userRole, roles[i].name) == 0) {
            roleFound = 1;
            printf("Available resources for %s:\n", userRole);
            for (j = 0; j < roles[i].resourceCount; j++) {
                printf("%s\n", roles[i].resources[j].name);
            }
            break;
        }
    }

    if (!roleFound) {
        printf("Invalid role.\n");
    }

    return 0;
}