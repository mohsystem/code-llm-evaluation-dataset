#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_LINE 1024

typedef struct {
    char key[256];
    char value[256];
} Record;

int compare(const void *a, const void *b) {
    Record *ra = (Record *)a;
    Record *rb = (Record *)b;
    return strcmp(ra->key, rb->key);
}

int main() {
    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }
    Record records[MAX_RECORDS];
    int count = 0;
    char line[MAX_LINE];
    while (fgets(line, MAX_LINE, fp) != NULL) {
        char *token = strtok(line, "-");
        strcpy(records[count].key, token);
        token = strtok(NULL, "
");
        strcpy(records[count].value, token);
        count++;
    }
    qsort(records, count, sizeof(Record), compare);
    for (int i = 0; i < count; i++) {
        printf("%s-%s
", records[i].key, records[i].value);
    }
    fclose(fp);
    return 0;
}