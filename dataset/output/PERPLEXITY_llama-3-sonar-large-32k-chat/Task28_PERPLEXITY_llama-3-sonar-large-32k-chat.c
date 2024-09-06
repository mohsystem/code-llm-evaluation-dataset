#include <stdio.h>
#include <string.h>

char* likes(char* names[], int size) {
    static char result[100];
    if (size == 0) {
        strcpy(result, "no one likes this");
    } else if (size == 1) {
        sprintf(result, "%s likes this", names[0]);
    } else if (size == 2) {
        sprintf(result, "%s and %s like this", names[0], names[1]);
    } else if (size == 3) {
        sprintf(result, "%s, %s and %s like this", names[0], names[1], names[2]);
    } else {
        sprintf(result, "%s, %s and %d others like this", names[0], names[1], size - 2);
    }
    return result;
}