#include <stdio.h>
#include <string.h>

int isValidWalk(char* walk[], int len) {
    int n = 0, s = 0, e = 0, w = 0;
    for (int i = 0; i < len; i++) {
        if (strcmp(walk[i], "n") == 0) n++;
        if (strcmp(walk[i], "s") == 0) s++;
        if (strcmp(walk[i], "e") == 0) e++;
        if (strcmp(walk[i], "w") == 0) w++;
    }
    return len == 10 && n == s && e == w;
}