// C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

int compare(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

char** readAndSortFile(const char* filePath, int* numRecords) {
    FILE* file = fopen(filePath, "r");
    if (file == NULL) {
        perror("Unable to open file");
        return NULL;
    }

    char** records = NULL;
    char line[MAX_LINE_LENGTH];
    int capacity = 0;

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        if (*numRecords >= capacity) {
            capacity = (capacity == 0) ? 1 : capacity * 2;
            records = (char**)realloc(records, capacity * sizeof(char*));
        }
        records[*numRecords] = strdup(line);
        (*numRecords)++;
    }

    fclose(file);

    qsort(records, *numRecords, sizeof(char*), compare);

    return records;
}

int main() {
    int numRecords = 0;
    char** sortedRecords = readAndSortFile("path_to_your_file.txt", &numRecords);

    for (int i = 0; i < numRecords; i++) {
        printf("%s", sortedRecords[i]);
        free(sortedRecords[i]);
    }

    free(sortedRecords);

    return 0;
}