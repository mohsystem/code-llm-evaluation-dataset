
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int main() {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Unable to open file\\n");
        return 1;
    }

    regex_t regex;
    int reti = regcomp(&regex, "^[0-9].*\\\\.$", REG_EXTENDED);
    if (reti) {
        fprintf(stderr, "Could not compile regex\\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\\n")] = 0;  // Remove newline
        reti = regexec(&regex, line, 0, NULL, 0);
        if (!reti) {
            printf("%s\\n", line);
        }
    }

    regfree(&regex);
    fclose(file);
    return 0;
}
