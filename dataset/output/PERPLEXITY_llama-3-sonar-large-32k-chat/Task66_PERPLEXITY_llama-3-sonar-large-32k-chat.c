#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LENGTH 1024

int main() {
    char cmd[MAX_CMD_LENGTH];
    printf("Enter a bash command: ");
    fgets(cmd, MAX_CMD_LENGTH, stdin);
    cmd[strcspn(cmd, "
")] = 0; // remove newline character

    FILE *fp = popen(cmd, "r");
    if (fp == NULL) {
        printf("Error executing command
");
        return 1;
    }

    char output[1024];
    while (fgets(output, 1024, fp) != NULL) {
        printf("%s", output);
    }

    pclose(fp);
    return 0;
}