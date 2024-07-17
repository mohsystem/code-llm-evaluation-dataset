// C

#include <stdio.h>
#include <string.h>

#define MAX_RESOURCES 3
#define MAX_KEY_LENGTH 10
#define MAX_VALUE_LENGTH 50

struct Resource {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
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
        if (strcmp(userInput, resources[i].key) == 0) {
            printf("Access granted to: %s
", resources[i].value);
            return 0;
        }
    }

    printf("Access denied.
");
    return 0;
}