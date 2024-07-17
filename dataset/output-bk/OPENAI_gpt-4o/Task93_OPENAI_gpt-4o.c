#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        perror("Unable to open file");
        return 1;
    }

    char **lines = NULL;
    size_t count = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        lines = realloc(lines, (count + 1) * sizeof(char *));
        lines[count] = strdup(line);
        count++;
    }
    fclose(file);

    qsort(lines, count, sizeof(char *), compare);

    file = fopen("sorted_data.txt", "w");
    if (file == NULL) {
        perror("Unable to open file");
        return 1;
    }

    for (size_t i = 0; i < count; i++) {
        fputs(lines[i], file);
        free(lines[i]);
    }
    free(lines);
    fclose(file);

    return 0;
}