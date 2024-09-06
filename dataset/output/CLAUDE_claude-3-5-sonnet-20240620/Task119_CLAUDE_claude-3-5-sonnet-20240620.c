
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FIELDS 100

void processCSV(const char* filePath) {
    FILE* file = fopen(filePath, "r");
    if (file == NULL) {
        printf("Error opening file.\\n");
        return;
    }

    char line[MAX_LINE_LENGTH];
    char* token;
    int fieldCount;

    if (fgets(line, sizeof(line), file)) {
        printf("CSV Header: %s", line);
    }

    while (fgets(line, sizeof(line), file)) {
        fieldCount = 0;
        token = strtok(line, ",");
        
        printf("Row: ");
        while (token != NULL && fieldCount < MAX_FIELDS) {
            printf("%s ", token);
            token = strtok(NULL, ",");
            fieldCount++;
        }
        printf("\\n");
    }

    fclose(file);
}

int main() {
    const char* filePath = "example.csv";
    processCSV(filePath);
    return 0;
}
