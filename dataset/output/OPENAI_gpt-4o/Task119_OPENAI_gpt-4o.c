#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readCSV(const char *filePath) {
    FILE *file = fopen(filePath, "r");
    char line[1024];

    if (file == NULL) {
        perror("File opening failed");
        return;
    }

    while (fgets(line, 1024, file)) {
        char *token = strtok(line, ",");
        while (token) {
            printf("%s ", token);
            token = strtok(NULL, ",");
        }
        printf("\n");
    }

    fclose(file);
}

void writeCSV(const char *filePath, const char *data[][3], int rows) {
    FILE *file = fopen(filePath, "w");

    if (file == NULL) {
        perror("File opening failed");
        return;
    }

    for (int i = 0; i < rows; i++) {
        fprintf(file, "%s,%s,%s\n", data[i][0], data[i][1], data[i][2]);
    }

    fclose(file);
}

int main() {
    const char *data[][3] = {
        {"Name", "Age", "City"},
        {"Alice", "30", "New York"},
        {"Bob", "25", "Los Angeles"},
        {"Charlie", "35", "Chicago"}
    };

    const char *filePath = "example.csv";

    writeCSV(filePath, data, 4);
    readCSV(filePath);

    return 0;
}