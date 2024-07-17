#include <stdio.h>
#include <regex.h>

#define MAX_LINE_LENGTH 256

int main() {
    FILE *file = fopen("file.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    regex_t regex;
    int reti;

    reti = regcomp(&regex, "^[0-9].*\\.$", REG_EXTENDED);
    if (reti) {
        fprintf(stderr, "Could not compile regex
");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        reti = regexec(&regex, line, 0, NULL, 0);
        if (!reti) {
            printf("%s", line);
        }
    }

    fclose(file);
    regfree(&regex);

    return 0;
}