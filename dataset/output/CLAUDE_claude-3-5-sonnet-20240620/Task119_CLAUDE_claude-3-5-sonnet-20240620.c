
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FIELDS 100

void parse_csv_line(char *line, char **fields, int *num_fields) {
    *num_fields = 0;
    char *token = strtok(line, ",");
    while (token != NULL && *num_fields < MAX_FIELDS) {
        fields[*num_fields] = token;
        (*num_fields)++;
        token = strtok(NULL, ",");
    }
}

int main() {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Error opening file\
");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    char *fields[MAX_FIELDS];
    int num_fields;

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\
")] = 0;  // Remove newline
        parse_csv_line(line, fields, &num_fields);

        for (int i = 0; i < num_fields; i++) {
            printf("%s\\t", fields[i]);
        }
        printf("\
");
    }

    fclose(file);
    return 0;
}
