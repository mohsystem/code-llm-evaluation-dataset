#include <stdio.h>
#include <regex.h>

#define MAX_LINE_LENGTH 256

int main() {
    FILE *file = fopen("path_to_your_file.txt", "r");
    if (file != NULL) {
        char line[MAX_LINE_LENGTH];
        regex_t regex;
        int reti;
        char msgbuf[100];

        reti = regcomp(&regex, "^[0-9].*\\.$", 0);
        if (reti) {
            fprintf(stderr, "Could not compile regex\n");
            return 1;
        }

        while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
            reti = regexec(&regex, line, 0, NULL, 0);
            if (!reti) {
                printf("%s", line);
            } else if (reti != REG_NOMATCH) {
                regerror(reti, &regex, msgbuf, sizeof(msgbuf));
                fprintf(stderr, "Regex match failed: %s\n", msgbuf);
                return 1;
            }
        }

        fclose(file);
        regfree(&regex);
    } else {
        printf("Unable to open file\n");
    }
    return 0;
}