#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    char name[6];
} Robot;

static char usedNames[10000][6] = {0};
static int usedNamesCount = 0;

void generateName(Robot* robot) {
    srand(time(NULL));
    while (1) {
        char name[6];
        name[0] = 'A' + rand() % 26;
        name[1] = 'A' + rand() % 26;
        sprintf(&name[2], "%03d", rand() % 900 + 100);
        name[5] = '\0';
        int found = 0;
        for (int i = 0; i < usedNamesCount; i++) {
            if (strcmp(name, usedNames[i]) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(robot->name, name);
            strcpy(usedNames[usedNamesCount], name);
            usedNamesCount++;
            return;
        }
    }
}

void reset(Robot* robot) {
    generateName(robot);
}

int main() {
    Robot robot;
    generateName(&robot);
    printf("%s
", robot.name);
    reset(&robot);
    printf("%s
", robot.name);
    return 0;
}