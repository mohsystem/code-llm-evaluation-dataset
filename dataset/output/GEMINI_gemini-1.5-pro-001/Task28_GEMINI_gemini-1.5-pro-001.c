#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* likes(char** names, int names_size) {
    char* result = malloc(100 * sizeof(char));
    switch (names_size) {
        case 0:
            strcpy(result, "no one likes this");
            break;
        case 1:
            sprintf(result, "%s likes this", names[0]);
            break;
        case 2:
            sprintf(result, "%s and %s like this", names[0], names[1]);
            break;
        case 3:
            sprintf(result, "%s, %s and %s like this", names[0], names[1], names[2]);
            break;
        default:
            sprintf(result, "%s, %s and %d others like this", names[0], names[1], names_size - 2);
            break;
    }
    return result;
}