#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

// Structure to store key-value pairs
typedef struct {
    char key[MAX_LINE_LENGTH];
    char value[MAX_LINE_LENGTH];
} KeyValuePair;

// Comparison function for qsort() to sort by key
int compare_key_value_pairs(const void* a, const void* b) {
    KeyValuePair* pair_a = (KeyValuePair*)a;
    KeyValuePair* pair_b = (KeyValuePair*)b;
    return strcmp(pair_a->key, pair_b->key);
}

int main() {
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    KeyValuePair* records = NULL;
    int num_records = 0;
    char line[MAX_LINE_LENGTH];

    // Read records from file
    while (fgets(line, sizeof(line), file) != NULL) {
        // Remove trailing newline character
        line[strcspn(line, "\n")] = 0;

        // Allocate memory for new record
        records = (KeyValuePair*)realloc(records, (num_records + 1) * sizeof(KeyValuePair));
        if (records == NULL) {
            perror("Memory allocation failed");
            fclose(file);
            return 1;
        }

        // Parse key and value
        char* delimiter = strchr(line, '=');
        if (delimiter != NULL) {
            *delimiter = '\0';
            strcpy(records[num_records].key, line);
            strcpy(records[num_records].value, delimiter + 1);
            num_records++;
        }
    }

    fclose(file);

    // Sort records by key
    qsort(records, num_records, sizeof(KeyValuePair), compare_key_value_pairs);

    // Print sorted records
    for (int i = 0; i < num_records; i++) {
        printf("%s=%s\n", records[i].key, records[i].value);
    }

    // Free allocated memory
    free(records);

    return 0;
}