#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_LINE 100

typedef struct {
    char key[50];
    char value[50];
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
    int i = 0;
    char line[MAX_LINE];
    while (fgets(line, MAX_LINE, fp) != NULL) {
        char *token = strtok(line, "-");
        strcpy(records[i].key, token);
        token = strtok(NULL, "
");
        strcpy(records[i].value, token);
        i++;
    }
    qsort(records, i, sizeof(Record), compare);
    for (int j = 0; j < i; j++) {
        printf("%s-%s
", records[j].key, records[j].value);
    }
    fclose(fp);
    return 0;
}