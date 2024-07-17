#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void processCSV(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("File opening failed");
        return;
    }
    
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        char* token = strtok(line, ",");
        while (token) {
            printf("%s ", token);
            token = strtok(NULL, ",");
        }
        printf("
");
    }

    fclose(file);
}

int main() {
    processCSV("data.csv");
    return 0;
}