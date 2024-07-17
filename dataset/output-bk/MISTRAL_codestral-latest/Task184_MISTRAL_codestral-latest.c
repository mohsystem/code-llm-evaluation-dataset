#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define UPPER "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define DIGITS "0123456789"
#define LENGTH 5
#define MAX_ROBOTS 1000

char* generateName(char* existingNames[], int* numExistingNames) {
    char* name = malloc(sizeof(char) * (LENGTH + 1));
    int i, j;
    for (i = 0; i < MAX_ROBOTS; i++) {
        for (j = 0; j < 2; j++) {
            name[j] = UPPER[rand() % 26];
        }
        for (j = 2; j < LENGTH; j++) {
            name[j] = DIGITS[rand() % 10];
        }
        name[LENGTH] = '\0';
        for (j = 0; j < *numExistingNames; j++) {
            if (strcmp(name, existingNames[j]) == 0) {
                break;
            }
        }
        if (j == *numExistingNames) {
            existingNames[*numExistingNames] = name;
            (*numExistingNames)++;
            return name;
        }
        free(name);
    }
    return NULL;
}

int main() {
    srand(time(0));
    char* robots[MAX_ROBOTS];
    int numRobots = 0;
    int i;
    for (i = 0; i < MAX_ROBOTS; i++) {
        robots[i] = generateName(robots, &numRobots);
    }
    printf("%d
", numRobots == MAX_ROBOTS);  // Should print: 1
    for (i = 0; i < MAX_ROBOTS; i++) {
        free(robots[i]);
    }
    return 0;
}