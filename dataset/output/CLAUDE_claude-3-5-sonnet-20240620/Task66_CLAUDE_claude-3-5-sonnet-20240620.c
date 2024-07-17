
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <regex.h>

#define MAX_COMMAND_LENGTH 1000
#define MAX_OUTPUT_LENGTH 10000

int validate_command(const char* command) {
    regex_t regex;
    int reti;

    // Check if command is empty
    if (strlen(command) == 0) {
        return 0;
    }

    // Compile regex to check for semicolons, pipes, or redirections
    reti = regcomp(&regex, "[;|><]", REG_EXTENDED);
    if (reti) {
        fprintf(stderr, "Could not compile regex\
");
        exit(1);
    }

    // Execute regex
    reti = regexec(&regex, command, 0, NULL, 0);
    regfree(&regex);

    if (!reti) {
        return 0; // Match found, invalid command
    } else if (reti == REG_NOMATCH) {
        return 1; // No match, valid command
    } else {
        char msgbuf[100];
        regerror(reti, &regex, msgbuf, sizeof(msgbuf));
        fprintf(stderr, "Regex match failed: %s\
", msgbuf);
        exit(1);
    }
}

int main() {
    char command[MAX_COMMAND_LENGTH];
    char output[MAX_OUTPUT_LENGTH];

    printf("Enter a bash command: ");
    fgets(command, sizeof(command), stdin);
    command[strcspn(command, "\
")] = 0; // Remove newline

    if (validate_command(command)) {
        FILE* fp = popen(command, "r");
        if (fp == NULL) {
            printf("Failed to run command\
");
            return 1;
        }

        while (fgets(output, sizeof(output), fp) != NULL) {
            printf("%s", output);
        }

        pclose(fp);
    } else {
        printf("Invalid command format or content.\
");
    }

    return 0;
}
