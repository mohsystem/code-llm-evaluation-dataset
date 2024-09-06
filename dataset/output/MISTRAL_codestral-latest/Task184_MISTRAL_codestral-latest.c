#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define NAME_LENGTH 5
#define UPPERCASE_LETTERS "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define DIGITS "0123456789"
#define NUM_ROBOTS 1000

char* generate_name(bool* existing_names) {
    char* name = malloc(NAME_LENGTH + 1);
    bool is_unique;
    do {
        for (int i = 0; i < NAME_LENGTH; i++) {
            const char* chars = (i < 2) ? UPPERCASE_LETTERS : DIGITS;
            name[i] = chars[rand() % strlen(chars)];
        }
        name[NAME_LENGTH] = '\0';
        is_unique = true;
        for (int i = 0; i < NUM_ROBOTS; i++) {
            if (existing_names[i] && strcmp(name, (char*)(i + 1)) == 0) {
                is_unique = false;
                break;
            }
        }
    } while (!is_unique);
    return name;
}

int main() {
    srand(time(NULL));
    bool existing_names[NUM_ROBOTS] = {false};
    char* names[NUM_ROBOTS];
    for (int i = 0; i < NUM_ROBOTS; i++) {
        names[i] = generate_name(existing_names);
        existing_names[i] = true;
    }
    for (int i = 0; i < NUM_ROBOTS; i++) {
        for (int j = i + 1; j < NUM_ROBOTS; j++) {
            if (strcmp(names[i], names[j]) == 0) {
                printf("Names are not unique\n");
                return 1;
            }
        }
        free(names[i]);
    }
    printf("All names are unique\n");
    return 0;
}