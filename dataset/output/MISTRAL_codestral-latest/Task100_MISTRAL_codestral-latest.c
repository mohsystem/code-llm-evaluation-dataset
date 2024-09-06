#include <stdio.h>
#include <regex.h>

int main(int argc, char* argv[]) {
    const char* pattern = argv[1];
    const char* fileName = argv[2];

    FILE* file = fopen(fileName, "r");
    if (file != NULL) {
        regex_t regexPattern;
        regcomp(&regexPattern, pattern, REG_EXTENDED);

        char line[256];
        while (fgets(line, sizeof(line), file)) {
            regmatch_t match;
            if (regexec(&regexPattern, line, 1, &match, 0) == 0) {
                printf("%.*s\n", match.rm_eo - match.rm_so, line + match.rm_so);
            }
        }

        fclose(file);
        regfree(&regexPattern);
    } else {
        printf("File not found: %s\n", fileName);
    }

    return 0;
}