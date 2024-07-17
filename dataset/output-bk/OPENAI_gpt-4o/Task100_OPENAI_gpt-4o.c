#include <regex.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: <pattern> <filename>
");
        return 1;
    }
    const char *pattern = argv[1];
    const char *filename = argv[2];

    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("fopen");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *content = malloc(length);
    if (!content) {
        fclose(file);
        return 1;
    }
    fread(content, 1, length, file);
    fclose(file);

    regex_t regex;
    regcomp(&regex, pattern, 0);
    regmatch_t match;
    const char *p = content;

    while (regexec(&regex, p, 1, &match, 0) == 0) {
        printf("%.*s
", (int)(match.rm_eo - match.rm_so), p + match.rm_so);
        p += match.rm_eo;
    }

    regfree(&regex);
    free(content);
    return 0;
}