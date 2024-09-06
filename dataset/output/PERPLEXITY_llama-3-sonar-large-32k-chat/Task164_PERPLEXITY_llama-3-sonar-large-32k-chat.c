#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b) {
    char** str1 = (char**)a;
    char** str2 = (char**)b;
    char* token1 = strtok(*str1, " ");
    token1 = strtok(NULL, " ");
    char* token2 = strtok(*str2, " ");
    token2 = strtok(NULL, " ");
    if (strlen(token1) != strlen(token2)) {
        return strlen(token1) - strlen(token2);
    } else {
        return strcmp(token1, token2);
    }
}

void lastNameLensort(char** names, int size) {
    qsort(names, size, sizeof(char*), compare);
}