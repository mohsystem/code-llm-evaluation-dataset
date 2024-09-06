// C does not have built-in support for regular expressions, so we'll use POSIX regex
#include <regex.h>
#include <stdio.h>

int main() {
    FILE *file = fopen("input.txt", "r");
    char line[1024];
    regex_t regex;
    regcomp(&regex, "^\\d+.*\\.$", 0);
    while (fgets(line, 1024, file)) {
        if (!regexec(&regex, line, 0, NULL, 0)) {
            printf("%s", line);
        }
    }
    regfree(&regex);
    fclose(file);
    return 0;
}