#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void likes(char *names[], int n) {
    if (n == 0) {
        printf("no one likes this");
    } else if (n == 1) {
        printf("%s likes this", names[0]);
    } else if (n == 2) {
        printf("%s and %s like this", names[0], names[1]);
    } else if (n == 3) {
        printf("%s, %s and %s like this", names[0], names[1], names[2]);
    } else {
        printf("%s, %s and %d others like this", names[0], names[1], n-2);
    }
}