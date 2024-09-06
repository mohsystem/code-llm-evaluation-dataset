
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define MAX_LINE_LENGTH 1000

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <regex_pattern> <file_name>\\n", argv[0]);
        return 1;
    }

    const char *pattern = argv[1];
    const char *fileName = argv[2];

    regex_t regex;
    int reti = regcomp(&regex, pattern, REG_EXTENDED);
    if (reti) {
        fprintf(stderr, "Could not compile regex\\n");
        return 1;
    }

    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        perror("Error opening file");
        regfree(&regex);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        if (regexec(&regex, line, 0, NULL, 0) == 0) {
            printf("%s", line);
        }
    }

    fclose(file);
    regfree(&regex);
    return 0;
}
