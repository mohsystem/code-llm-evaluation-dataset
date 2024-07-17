// C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char* key;
    char* value;
} Entry;

int compare(const void* a, const void* b) {
    return strcmp(((Entry*)a)->key, ((Entry*)b)->key);
}

int main() {
    FILE* file = fopen("file.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    Entry entries[1024];
    int count = 0;
    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, file)) {
        char* key = strtok(line, "=");
        char* value = strtok(NULL, "=");
        if (value != NULL) {
            entries[count].key = strdup(key);
            entries[count].value = strdup(value);
            count++;
        }
    }

    fclose(file);

    qsort(entries, count, sizeof(Entry), compare);

    for (int i = 0; i < count; i++) {
        printf("%s=%s
", entries[i].key, entries[i].value);
        free(entries[i].key);
        free(entries[i].value);
    }

    return 0;
}