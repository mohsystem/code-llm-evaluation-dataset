#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char key[100];
    char value[100];
} Record;

int compareRecords(const void *a, const void *b) {
    return strcmp(((Record *)a)->key, ((Record *)b)->key);
}

Record* readFile(const char *filename, int *length) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    Record *records = NULL;
    char line[256];
    *length = 0;

    while (fgets(line, sizeof(line), file)) {
        records = realloc(records, (*length + 1) * sizeof(Record));
        sscanf(line, "%99[^=]=%99[^\n]", records[*length].key, records[*length].value);
        (*length)++;
    }

    fclose(file);
    return records;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    int length;
    Record *records = readFile(argv[1], &length);
    qsort(records, length, sizeof(Record), compareRecords);

    for (int i = 0; i < length; i++) {
        printf("%s = %s\n", records[i].key, records[i].value);
    }

    free(records);
    return 0;
}