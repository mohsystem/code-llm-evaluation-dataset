#include <stdio.h>
#include <regex.h>
#include <string.h>

void match_lines(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Cannot open file");
        return;
    }
    
    char line[256];
    regex_t regex;
    regcomp(&regex, "^[0-9].*\\.$", REG_NOSUB | REG_EXTENDED);

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0; // Remove trailing newline character
        if (regexec(&regex, line, 0, NULL, 0) == 0) {
            printf("%s\n", line);
        }
    }

    regfree(&regex);
    fclose(file);
}

int main() {
    const char *filename = "input.txt";
    match_lines(filename);
    return 0;
}