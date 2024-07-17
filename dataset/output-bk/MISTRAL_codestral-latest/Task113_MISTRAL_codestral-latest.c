#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int main() {
    char input[MAX_SIZE];
    char result[MAX_SIZE] = "";

    printf("Enter strings to concatenate (enter 'end' to stop):
");
    fgets(input, MAX_SIZE, stdin);

    while (strcmp(input, "end
") != 0) {
        strcat(result, input);
        fgets(input, MAX_SIZE, stdin);
    }

    printf("Concatenated string: %s
", result);

    return 0;
}