#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NAME_LENGTH 5

typedef struct Robot {
    char name[NAME_LENGTH + 1];
} Robot;

char usedNames[1000][NAME_LENGTH + 1];
int usedCount = 0;

void generateRandomName(char* name) {
    const char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char digits[] = "0123456789";

    for(int i = 0; i < 2; i++) {
        name[i] = letters[rand() % 26];
    }
    for(int i = 2; i < 5; i++) {
        name[i] = digits[rand() % 10];
    }
    name[NAME_LENGTH] = '\0';
}

int isNameUnique(const char* name) {
    for(int i = 0; i < usedCount; i++) {
        if(strcmp(usedNames[i], name) == 0) {
            return 0;
        }
    }
    return 1;
}

void setName(Robot* robot) {
    do {
        generateRandomName(robot->name);
    } while(!isNameUnique(robot->name));
    strcpy(usedNames[usedCount++], robot->name);
}

void reset(Robot* robot) {
    setName(robot);
}

int main() {
    srand(time(NULL));

    Robot robot;
    setName(&robot);
    printf("%s\n", robot.name);
    reset(&robot);
    printf("%s\n", robot.name);

    return 0;
}