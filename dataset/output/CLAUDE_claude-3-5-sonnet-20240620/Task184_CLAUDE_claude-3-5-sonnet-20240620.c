
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ROBOTS 1000
#define NAME_LENGTH 6

char used_names[MAX_ROBOTS][NAME_LENGTH];
int used_count = 0;

void generate_name(char *name) {
    const char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char digits[] = "0123456789";

    do {
        name[0] = letters[rand() % 26];
        name[1] = letters[rand() % 26];
        name[2] = digits[rand() % 10];
        name[3] = digits[rand() % 10];
        name[4] = digits[rand() % 10];
        name[5] = '\\0';
    } while (used_count > 0 && strstr((char*)used_names, name) != NULL);

    strcpy(used_names[used_count++], name);
}

typedef struct {
    char name[NAME_LENGTH];
} Robot;

void robot_init(Robot *robot) {
    generate_name(robot->name);
}

void robot_reset(Robot *robot) {
    generate_name(robot->name);
}

int main() {
    srand(time(NULL));

    Robot robot;
    robot_init(&robot);
    printf("%s\\n", robot.name);

    robot_reset(&robot);
    printf("%s\\n", robot.name);

    return 0;
}
