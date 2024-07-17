#include <stdio.h>
#include <regex.h>

void match_lines(const char *file_name) {
    FILE *file = fopen(file_name, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    regex_t regex;
    int reti = regcomp(&regex, "^[0-9].*\.$", REG_EXTENDED);
    if (reti) {
        fclose(file);
        fprintf(stderr, "Could not compile regex
");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        reti = regexec(&regex, line, 0, NULL, 0);
        if (!reti) {
            printf("%s", line);
        }
    }

    regfree(&regex);
    fclose(file);
}

int main() {
    const char *file_name = "input.txt";
    match_lines(file_name);
    return 0;
}