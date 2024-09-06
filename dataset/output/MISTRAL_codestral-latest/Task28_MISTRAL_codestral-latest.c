#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void likes(size_t n, char *names[n]) {
    switch (n) {
        case 0: printf("no one likes this"); break;
        case 1: printf("%s likes this", names[0]); break;
        case 2: printf("%s and %s like this", names[0], names[1]); break;
        case 3: printf("%s, %s and %s like this", names[0], names[1], names[2]); break;
        default: printf("%s, %s and %zu others like this", names[0], names[1], n - 2); break;
    }
}