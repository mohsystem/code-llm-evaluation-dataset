#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

int main() {
    FILE *fp;
    regex_t regex;
    char line[1024];
    int reti;

    fp = fopen("input.txt", "r");
    if (!fp) {
        perror("Error opening file");
        return(-1);
    }

    reti = regcomp(&regex, "^[0-9]+.*\\.$", 0);
    if (reti) {
        fprintf(stderr, "Could not compile regex
");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)) {
        reti = regexec(&regex, line, 0, NULL, 0);
        if (!reti) {
            printf("%s", line);
        }
    }

    fclose(fp);
    regfree(&regex);
    return 0;
}