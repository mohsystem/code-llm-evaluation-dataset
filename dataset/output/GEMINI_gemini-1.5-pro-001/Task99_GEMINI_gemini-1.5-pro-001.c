#include <stdio.h>
#include <regex.h>

int main() {
    FILE *fp = fopen("input.txt", "r");
    char line[256];
    regex_t regex;
    int reti;

    if (regcomp(&regex, "^[0-9]+\\.$", REG_EXTENDED)) {
        fprintf(stderr, "Could not compile regex\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        reti = regexec(&regex, line, 0, NULL, 0);
        if (!reti) {
            printf("%s", line);
        }
    }

    fclose(fp);
    regfree(&regex);
    return 0;
}