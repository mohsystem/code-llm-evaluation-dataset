#include <stdio.h>
#include <regex.h>

int main() {
    FILE *file = fopen("input.txt", "r");
    char line[256];
    regex_t regex;
    int reti;

    reti = regcomp(&regex, "^[0-9]+.*\\.$", REG_EXTENDED);
    if (reti) {
        fprintf(stderr, "Could not compile regex
");
        return 1;
    }

    while (fgets(line, sizeof(line), file)) {
        reti = regexec(&regex, line, 0, NULL, 0);
        if (!reti) {
            printf("%s", line);
        } 
    }

    fclose(file);
    regfree(&regex);
    return 0;
}