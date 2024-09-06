#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Structure to store key-value pairs
struct KeyValuePair {
    char key[MAX_LINE_LENGTH];
    char value[MAX_LINE_LENGTH];
};

// Comparison function for qsort, comparing keys
int compareByKey(const void* a, const void* b) {
    return strcmp(((struct KeyValuePair*)a)->key, ((struct KeyValuePair*)b)->key);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    char* filePath = argv[1];
    struct KeyValuePair keyValuePairs[MAX_LINE_LENGTH];
    int count = 0;

    // Read key-value pairs from the file
    FILE* file = fopen(filePath, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filePath);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file) != NULL) {
        char* token = strtok(line, " ");
        if (token != NULL) {
            strcpy(keyValuePairs[count].key, token);

            token = strtok(NULL, "\n");
            if (token != NULL) {
                strcpy(keyValuePairs[count].value, token);
                count++;
            }
        }
    }
    fclose(file);

    // Sort the key-value pairs based on keys
    qsort(keyValuePairs, count, sizeof(struct KeyValuePair), compareByKey);

    // Print the sorted key-value pairs
    for (int i = 0; i < count; i++) {
        printf("%s %s\n", keyValuePairs[i].key, keyValuePairs[i].value);
    }

    return 0;
}