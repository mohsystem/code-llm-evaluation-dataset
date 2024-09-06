#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    char name[6];
} Robot;

static char usedNames[100000][6] = {0};
static int usedNamesCount = 0;

void generateName(Robot* robot) {
    srand(time(NULL));
    while (true) {
        char name[6];
        name[0] = 'A' + rand() % 26;
        name[1] = 'A' + rand() % 26;
        sprintf(name + 2, "%03d", rand() % 1000);
        int exists = 0;
        for (int i = 0; i < usedNamesCount; i++) {
            if (strcmp(usedNames[i], name) == 0) {
                exists = 1;
                break;
            }
        }
        if (!exists) {
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
    printf("%s\n", robot.name);
    reset(&robot);
    printf("%s\n", robot.name);
    return 0;
}