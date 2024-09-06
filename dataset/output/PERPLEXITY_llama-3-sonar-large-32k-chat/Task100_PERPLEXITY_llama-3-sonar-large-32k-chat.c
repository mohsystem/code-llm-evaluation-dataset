// C does not have built-in support for regular expressions, so we'll use the POSIX regex library
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s pattern file_name\n", argv[0]);
        return 1;
    }

    regex_t regex;
    int reti = regcomp(&regex, argv[1], 0);
    if (reti) {
        fprintf(stderr, "Could not compile regex\n");
        return 1;
    }

    FILE* file = fopen(argv[2], "r");
    if (!file) {
        fprintf(stderr, "Failed to open file %s\n", argv[2]);
        return 1;
    }

    char line[1024];
    while (fgets(line, 1024, file)) {
        regmatch_t pmatch;
        while (!regexec(&regex, line, 1, &pmatch, 0)) {
            for (int i = pmatch.rm_so; i < pmatch.rm_eo; i++) {
                putchar(line[i]);
            }
            putchar('\n');
            memmove(line, line + pmatch.rm_so + pmatch.rm_eo, strlen(line + pmatch.rm_so + pmatch.rm_eo) + 1);
        }
    }

    fclose(file);
    regfree(&regex);
    return 0;
}