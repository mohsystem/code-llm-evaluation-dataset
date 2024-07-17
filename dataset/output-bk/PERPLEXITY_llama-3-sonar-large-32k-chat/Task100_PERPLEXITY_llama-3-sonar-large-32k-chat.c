#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <pattern> <file>
", argv[0]);
        return 1;
    }
    char *pattern = argv[1];
    char *file = argv[2];
    regex_t regex;
    int reti;
    if ((reti = regcomp(&regex, pattern, 0)) != 0) {
        printf("Could not compile regex
");
        return 1;
    }
    FILE *fp;
    if ((fp = fopen(file, "r")) == NULL) {
        printf("Could not open file
");
        return 1;
    }
    char line[1024];
    while (fgets(line, sizeof(line), fp) != NULL) {
        regmatch_t pmatch;
        while ((reti = regexec(&regex, line, 1, &pmatch, 0)) == 0) {
            printf("%.*s
", pmatch.rm_eo - pmatch.rm_so, line + pmatch.rm_so);
            regoff_t offset = pmatch.rm_eo;
            line[offset] = '\0';
        }
    }
    fclose(fp);
    regfree(&regex);
    return 0;
}