#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

typedef struct {
    char key[MAX_LEN];
    char value[MAX_LEN];
} Record;

int compare(const void *a, const void *b) {
    return strcmp(((Record *)a)->key, ((Record *)b)->key);
}

int main() {
    FILE *file = fopen("file.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    Record records[100];
    int count = 0;
    char line[MAX_LEN * 2];

    while (fgets(line, sizeof(line), file)) {
        char *key = strtok(line, "=");
        char *value = strtok(NULL, "=");
        if (key != NULL && value != NULL) {
            strncpy(records[count].key, key, MAX_LEN);
            strncpy(records[count].value, value, MAX_LEN);
            count++;
        }
    }

    fclose(file);

    qsort(records, count, sizeof(Record), compare);

    for (int i = 0; i < count; i++) {
        printf("%s=%s
", records[i].key, records[i].value);
    }

    return 0;
}