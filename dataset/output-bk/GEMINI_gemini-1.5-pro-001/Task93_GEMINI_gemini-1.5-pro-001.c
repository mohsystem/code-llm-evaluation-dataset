#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 100

// Structure to represent a key-value pair
struct KeyValuePair {
    char key[MAX_LINE_LENGTH];
    char value[MAX_LINE_LENGTH];
};

// Function to compare key-value pairs based on keys
int comparePairs(const void *a, const void *b) {
    return strcmp(((struct KeyValuePair *)a)->key, ((struct KeyValuePair *)b)->key);
}

int main() {
    // Replace "input.txt" with the actual input file name
    char inputFileName[] = "input.txt";

    // Open the input file for reading
    FILE *inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Array to store key-value pairs
    struct KeyValuePair pairs[MAX_LINES];
    int numPairs = 0;

    // Read key-value pairs from the file
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), inputFile) != NULL) {
        // Remove trailing newline character
        line[strcspn(line, "
")] = 0;

        // Tokenize the line into key and value
        char *key = strtok(line, " ");
        char *value = strtok(NULL, " ");

        // Store the key-value pair in the array
        if (key != NULL && value != NULL) {
            strcpy(pairs[numPairs].key, key);
            strcpy(pairs[numPairs].value, value);
            numPairs++;
        }
    }

    // Close the input file
    fclose(inputFile);

    // Sort the key-value pairs based on keys
    qsort(pairs, numPairs, sizeof(struct KeyValuePair), comparePairs);

    // Print the sorted key-value pairs
    for (int i = 0; i < numPairs; i++) {
        printf("%s %s
", pairs[i].key, pairs[i].value);
    }

    return 0;
}