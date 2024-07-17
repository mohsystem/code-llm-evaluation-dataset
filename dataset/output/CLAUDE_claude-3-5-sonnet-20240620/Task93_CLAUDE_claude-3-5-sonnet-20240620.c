
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1000
#define MAX_RECORDS 1000

typedef struct {
    char *key;
    char *value;
} KeyValue;

int compare(const void *a, const void *b) {
    return strcmp(((KeyValue *)a)->key, ((KeyValue *)b)->key);
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    KeyValue records[MAX_RECORDS];
    int count = 0;
    char line[MAX_LINE];

    while (fgets(line, sizeof(line), file) && count < MAX_RECORDS) {
        char *colon = strchr(line, \':\');
        if (colon != NULL) {
            *colon = \'\\0\';
            records[count].key = strdup(line);
            records[count].value = strdup(colon + 1);
            count++;
        }
    }

    fclose(file);

    qsort(records, count, sizeof(KeyValue), compare);

    for (int i = 0; i < count; i++) {
        printf("%s: %s", records[i].key, records[i].value);
        free(records[i].key);
        free(records[i].value);
    }

    return 0;
}
