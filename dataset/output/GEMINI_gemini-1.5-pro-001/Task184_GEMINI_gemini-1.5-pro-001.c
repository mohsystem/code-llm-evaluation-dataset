#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAMES 1000

typedef struct {
    char name[6];
    int in_use;
} Robot;

Robot robots[MAX_NAMES];
int robot_count = 0;

void generate_name(char *name) {
    do {
        name[0] = 'A' + rand() % 26;
        name[1] = 'A' + rand() % 26;
        name[2] = '0' + rand() % 10;
        name[3] = '0' + rand() % 10;
        name[4] = '0' + rand() % 10;
        name[5] = '\0';
    } while (find_robot_by_name(name) != -1);
}

int find_robot_by_name(char *name) {
    for (int i = 0; i < robot_count; i++) {
        if (strcmp(robots[i].name, name) == 0 && robots[i].in_use) {
            return i;
        }
    }
    return -1;
}

Robot* create_robot() {
    if (robot_count >= MAX_NAMES) {
        return NULL;
    }
    
    Robot *robot = &robots[robot_count++];
    robot->in_use = 1;
    generate_name(robot->name);
    return robot;
}

void reset_robot(Robot *robot) {
    if (robot) {
        robot->in_use = 0;
        generate_name(robot->name);
        robot->in_use = 1;
    }
}

int main() {
    srand(time(NULL));
}