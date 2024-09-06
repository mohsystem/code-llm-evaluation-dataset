#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <pattern> <filename>\n", argv[0]);
        return 1;
    }

    const char *pattern = argv[1];
    const char *filename = argv[2];
    
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open the file!\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long fsize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *content = (char *)malloc(fsize + 1);
    fread(content, 1, fsize, file);
    content[fsize] = '\0';
    fclose(file);

    regex_t regex;
    regcomp(&regex, pattern, REG_EXTENDED);

    regmatch_t matches[1];
    const char *p = content;
    while (regexec(&regex, p, 1, matches, 0) != REG_NOMATCH) {
        printf("%.*s\n", matches[0].rm_eo - matches[0].rm_so, p + matches[0].rm_so);
        p += matches[0].rm_eo;
    }

    regfree(&regex);
    free(content);

    return 0;
}