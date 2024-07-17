
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME 256
#define MAX_COMMAND 512

int main() {
    char filename[MAX_FILENAME];
    char command[MAX_COMMAND];

    printf("Enter the filename: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\
")] = 0;  // Remove newline

    snprintf(command, sizeof(command), "cat %s", filename);

    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        printf("Failed to run command\
");
        return 1;
    }

    char output[1024];
    while (fgets(output, sizeof(output), fp) != NULL) {
        printf("%s", output);
    }

    pclose(fp);
    return 0;
}
