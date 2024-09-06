// C

#include <stdio.h>
#include <string.h>

#define MAX_RESOURCES 3
#define MAX_KEY_LENGTH 10

struct Resource {
    char key[MAX_KEY_LENGTH];
    char value[MAX_KEY_LENGTH];
};

int main() {
    struct Resource resources[MAX_RESOURCES] = {
        {"A", "Resource A"},
        {"B", "Resource B"},
        {"C", "Resource C"}
    };

    char userInput[MAX_KEY_LENGTH];
    printf("Enter a key to access a resource: ");
    scanf("%s", userInput);

    int i;
    for (i = 0; i < MAX_RESOURCES; i++) {
        if (strcmp(resources[i].key, userInput) == 0) {
            printf("Access granted to: %s\n", resources[i].value);
            return 0;
        }
    }

    printf("Access denied. Invalid key.\n");
    return 0;
}