#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char key[50];
    char value[50];
} Record;

int compare(const void *a, const void *b) {
    return strcmp(((Record *)a)->key, ((Record *)b)->key);
}

void read_and_sort(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Unable to open file.\n");
        return;
    }

    Record records[100];
    int count = 0;
    while (fscanf(file, "%s %s", records[count].key, records[count].value) != EOF) {
        count++;
    }
    fclose(file);

    qsort(records, count, sizeof(Record), compare);

    for (int i = 0; i < count; i++) {
        printf("%s %s\n", records[i].key, records[i].value);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please provide a filename as argument.\n");
        return 1;
    }
    read_and_sort(argv[1]);
    return 0;
}