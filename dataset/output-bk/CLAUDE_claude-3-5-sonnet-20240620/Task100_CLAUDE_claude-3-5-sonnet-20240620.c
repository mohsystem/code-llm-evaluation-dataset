
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define MAX_LINE_LENGTH 1000

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <regex_pattern> <file_name>\
", argv[0]);
        exit(1);
    }

    const char *regexPattern = argv[1];
    const char *fileName = argv[2];

    regex_t regex;
    int reti = regcomp(&regex, regexPattern, REG_EXTENDED);
    if (reti) {
        fprintf(stderr, "Could not compile regex\
");
        exit(1);
    }

    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file %s\
", fileName);
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    int lineNumber = 0;
    regmatch_t match;

    while (fgets(line, sizeof(line), file)) {
        lineNumber++;
        line[strcspn(line, "\
")] = 0;  // Remove newline

        if (regexec(&regex, line, 1, &match, 0) == 0) {
            printf("Line %d: %.*s\
", lineNumber, (int)(match.rm_eo - match.rm_so), line + match.rm_so);
        }
    }

    fclose(file);
    regfree(&regex);
    return 0;
}
