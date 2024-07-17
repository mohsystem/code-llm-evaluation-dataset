#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Structure to represent a key-value pair
struct KeyValue {
    char key[MAX_LINE_LENGTH];
    char value[MAX_LINE_LENGTH];
};

// Function to compare key-value pairs based on keys
int compareKeyValues(const void* a, const void* b) {
    return strcmp(((struct KeyValue*)a)->key, ((struct KeyValue*)b)->key);
}

int main(int argc, char* argv[]) {
    // Check if filename argument is provided
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>
", argv[0]);
        return 1;
    }

    char* filename = argv[1];
    FILE* fp = fopen(filename, "r");

    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s
", filename);
        return 1;
    }

    struct KeyValue keyValues[MAX_LINE_LENGTH];
    int count = 0;
    char line[MAX_LINE_LENGTH];

    // Read key-value pairs from the file
    while (fgets(line, sizeof(line), fp) != NULL) {
        // Assuming key and value are separated by a space " "
        sscanf(line, "%s %s", keyValues[count].key, keyValues[count].value);
        count++;
    }
    fclose(fp);

    // Sort the key-value pairs based on keys
    qsort(keyValues, count, sizeof(struct KeyValue), compareKeyValues);

    // Print sorted key-value pairs
    for (int i = 0; i < count; i++) {
        printf("%s %s
", keyValues[i].key, keyValues[i].value);
    }

    return 0;
}