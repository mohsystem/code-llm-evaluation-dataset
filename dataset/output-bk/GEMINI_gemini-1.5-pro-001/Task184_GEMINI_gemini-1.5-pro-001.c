#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAMES 10000

char* usedNames[MAX_NAMES];
int nameCount = 0;

char* generateUniqueName() {
    char *newName = malloc(sizeof(char) * 6);
    if (newName == NULL) {
        fprintf(stderr, "Memory allocation failed
");
        exit(1);
    }

    while (1) {
        // Generate random name
        for (int i = 0; i < 2; i++) {
            newName[i] = 'A' + (rand() % 26);
        }
        for (int i = 2; i < 5; i++) {
            newName[i] = '0' + (rand() % 10);
        }
        newName[5] = '\0';

        // Check if name is already used
        int nameUsed = 0;
        for (int i = 0; i < nameCount; i++) {
            if (strcmp(newName, usedNames[i]) == 0) {
                nameUsed = 1;
                break;
            }
        }
        if (!nameUsed) {
            break;
        }
    }

    // Add new name to list of used names
    usedNames[nameCount++] = newName;
    return newName;
}

void resetName(char** name) {
    // Remove old name from list of used names
    for (int i = 0; i < nameCount; i++) {
        if (strcmp(*name, usedNames[i]) == 0) {
            free(usedNames[i]);
            usedNames[i] = usedNames[nameCount - 1];
            nameCount--;
            break;
        }
    }

    // Generate new name
    *name = generateUniqueName();
}

int main() {
    srand(time(NULL)); 

    // Example usage
    char* robotName = generateUniqueName();
    printf("Robot name: %s
", robotName);

    resetName(&robotName);
    printf("New robot name: %s
", robotName);

    free(robotName);
    return 0;
}