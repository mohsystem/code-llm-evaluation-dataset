// C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main() {
    FILE *file = fopen("file.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int count = 0;
    char *records[100];
    while ((read = getline(&line, &len, file)) != -1) {
        line[strcspn(line, "\n")] = 0;
        records[count] = strdup(line);
        count++;
    }
    free(line);
    fclose(file);
    qsort(records, count, sizeof(char *), compare);
    for (int i = 0; i < count; i++) {
        printf("%s\n", records[i]);
        free(records[i]);
    }
    return 0;
}