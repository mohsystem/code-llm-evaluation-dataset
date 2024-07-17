#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 256

int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    char *lines[MAX_LINES];
    int count = 0;
    
    FILE *file = fopen("records.txt", "r");
    if (!file) {
        perror("Could not open file");
        return 1;
    }
    
    char buffer[MAX_LENGTH];
    while (fgets(buffer, sizeof(buffer), file)) {
        lines[count] = strdup(buffer);
        count++;
    }
    fclose(file);
    
    qsort(lines, count, sizeof(char *), compare);
    
    for (int i = 0; i < count; i++) {
        printf("%s", lines[i]);
        free(lines[i]);
    }
    
    return 0;
}