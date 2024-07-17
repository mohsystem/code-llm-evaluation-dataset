#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Robot {
    char name[6];
};

void generate_random_name(char *name) {
    name[0] = 'A' + rand() % 26;
    name[1] = 'A' + rand() % 26;
    sprintf(name + 2, "%03d", rand() % 1000);
    name[5] = '\0';
}

int is_unique(const char *name, char used_names[][6], int used_count) {
    for (int i = 0; i < used_count; ++i) {
        if (strcmp(name, used_names[i]) == 0)
            return 0;
    }
    return 1;
}

void reset_robot(struct Robot *robot, char used_names[][6], int *used_count) {
    do {
        generate_random_name(robot->name);
    } while (!is_unique(robot->name, used_names, *used_count));
    strcpy(used_names[*used_count], robot->name);
    (*used_count)++;
}

int main() {
    srand(time(0));
    char used_names[1000][6];
    int used_count = 0;

    struct Robot robot;
    reset_robot(&robot, used_names, &used_count);

    printf("%s
", robot.name);
    reset_robot(&robot, used_names, &used_count);
    printf("%s
", robot.name);

    return 0;
}