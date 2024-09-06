
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include <stdbool.h>

#define MAX_CMD_LENGTH 1024
#define MAX_OUTPUT_LENGTH 4096

bool validateCommand(const char* cmd) {
    regex_t regex;
    int reti;
    char msgbuf[100];

    if (strlen(cmd) == 0) {
        return false;
    }

    reti = regcomp(&regex, "(rm|sudo|mv|cp|chmod|chown)", REG_EXTENDED);
    if (reti) {
        fprintf(stderr, "Could not compile regex\\n");
        exit(1);
    }

    reti = regexec(&regex, cmd, 0, NULL, 0);
    regfree(&regex);

    if (!reti) {
        return false;
    }

    return true;
}

void executeCommand(const char* cmd, char* output) {
    FILE* fp;
    char path[MAX_OUTPUT_LENGTH];

    fp = popen(cmd, "r");
    if (fp == NULL) {
        sprintf(output, "Error executing command");
        return;
    }

    while (fgets(path, sizeof(path), fp) != NULL) {
        strcat(output, path);
    }

    pclose(fp);
}

int main() {
    char userInput[MAX_CMD_LENGTH];
    char output[MAX_OUTPUT_LENGTH];

    while (1) {
        printf("Enter a bash command (or 'exit' to quit): ");
        fgets(userInput, sizeof(userInput), stdin);
        userInput[strcspn(userInput, "\\n")] = 0;  // Remove newline

        if (strcmp(userInput, "exit") == 0) {
            break;
        }

        if (validateCommand(userInput)) {
            memset(output, 0, sizeof(output));
            executeCommand(userInput, output);
            printf("Output: %s\\n", output);
        } else {
            printf("Invalid or potentially dangerous command. Please try again.\\n");
        }
    }

    return 0;
}
