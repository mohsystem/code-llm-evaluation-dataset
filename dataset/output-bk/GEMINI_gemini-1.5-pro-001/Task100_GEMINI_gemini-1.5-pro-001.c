#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <regex> <filename>
", argv[0]);
        return 1;
    }

    char *regex = argv[1];
    char *filename = argv[2];

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    regex_t re;
    int reti = regcomp(&re, regex, 0);
    if (reti) {
        fprintf(stderr, "Could not compile regex
");
        return 1;
    }

    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        regmatch_t match;
        reti = regexec(&re, line, 1, &match, 0);
        if (!reti) {
            printf("%.*s
", (int)(match.rm_eo - match.rm_so), line + match.rm_so);
        }
    }

    regfree(&re);
    fclose(file);
    return 0;
}