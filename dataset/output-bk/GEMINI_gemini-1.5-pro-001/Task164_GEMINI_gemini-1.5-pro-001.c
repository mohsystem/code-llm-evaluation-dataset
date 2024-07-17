#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_last_names(const void *a, const void *b) {
    char *name1 = *(char **)a;
    char *name2 = *(char **)b;
    char *lastName1 = strrchr(name1, ' ') + 1;
    char *lastName2 = strrchr(name2, ' ') + 1;
    int lenDiff = strlen(lastName1) - strlen(lastName2);
    if (lenDiff != 0) {
        return lenDiff;
    } else {
        return strcmp(lastName1, lastName2);
    }
}

void lastNameLensort(char **names, int size) {
    qsort(names, size, sizeof(char *), compare_last_names);
}