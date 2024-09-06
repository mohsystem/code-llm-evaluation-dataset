#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <regex_pattern> <file_name>\n", argv[0]);
        return 1;
    }

    const char *pattern = argv[1];
    const char *file_name = argv[2];

    regex_t regex;
    int reti;
    char msgbuf[100];

    /* Compile regular expression */
    reti = regcomp(&regex, pattern, 0);
    if (reti) {
        fprintf(stderr, "Could not compile regex\n");
        return 1;
    }

    /* Open file for reading */
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", file_name);
        return 1;
    }

    char line[1024];
    while (fgets(line, sizeof(line), file) != NULL) {
        /* Execute regular expression */
        reti = regexec(&regex, line, 0, NULL, 0);
        if (!reti) {
            printf("%s", line);
        } else if (reti != REG_NOMATCH) {
            regerror(reti, &regex, msgbuf, sizeof(msgbuf));
            fprintf(stderr, "Regex match failed: %s\n", msgbuf);
            return 1;
        }
    }

    /* Free memory allocated to the compiled regex. */
    regfree(&regex);

    fclose(file);
    return 0;
}