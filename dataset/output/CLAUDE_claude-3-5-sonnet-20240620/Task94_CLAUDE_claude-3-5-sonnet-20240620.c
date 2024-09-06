
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_RECORDS 1000

typedef struct {
    char *key;
    char *value;
} KeyValue;

int compare(const void *a, const void *b) {
    return strcmp(((KeyValue *)a)->key, ((KeyValue *)b)->key);
}

void read_and_sort_records(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open file '%s'\\n", filename);
        return;
    }

    KeyValue records[MAX_RECORDS];
    int record_count = 0;
    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), file) && record_count < MAX_RECORDS) {
        char *colon = strchr(line, ':');
        if (colon != NULL) {
            *colon = '\\0';
            records[record_count].key = strdup(line);
            records[record_count].value = strdup(colon + 1);

            // Trim whitespace
            char *end = records[record_count].key + strlen(records[record_count].key) - 1;
            while (end > records[record_count].key && (*end == ' ' || *end == '\\t' || *end == '\\n')) *end-- = '\\0';
            char *start = records[record_count].value;
            while (*start == ' ' || *start == '\\t') start++;
            end = start + strlen(start) - 1;
            while (end > start && (*end == ' ' || *end == '\\t' || *end == '\\n')) *end-- = '\\0';
            records[record_count].value = strdup(start);

            record_count++;
        } else {
            printf("Warning: Skipping invalid line: %s", line);
        }
    }

    fclose(file);

    qsort(records, record_count, sizeof(KeyValue), compare);

    for (int i = 0; i < record_count; i++) {
        printf("%s: %s\\n", records[i].key, records[i].value);
        free(records[i].key);
        free(records[i].value);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\\n", argv[0]);
        return 1;
    }

    read_and_sort_records(argv[1]);
    return 0;
}
