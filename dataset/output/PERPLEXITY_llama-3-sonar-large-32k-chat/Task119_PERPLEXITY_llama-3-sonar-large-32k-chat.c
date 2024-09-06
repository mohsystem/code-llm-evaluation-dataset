// Note: C standard library does not have a built-in CSV parser. This implementation is a simple parser that assumes no quotes or escaped characters.
#include <stdio.h>
#include <string.h>

void parseCSV(const char* fileName) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Could not open file\n");
        return;
    }
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        char* token = strtok(line, ",");
        while (token != NULL) {
            printf("%s ", token);
            token = strtok(NULL, ",");
        }
        printf("\n");
    }
    fclose(file);
}

int main() {
    parseCSV("example.csv");
    return 0;
}