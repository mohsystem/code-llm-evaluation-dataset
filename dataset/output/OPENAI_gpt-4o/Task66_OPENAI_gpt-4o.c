#include <stdio.h>
#include <stdlib.h>

int main() {
    char command[256];
    printf("Enter a bash command: ");
    fgets(command, sizeof(command), stdin);

    FILE *fp;
    char path[1035];

    fp = popen(command, "r");
    if (fp == NULL) {
        printf("Failed to run command\n");
        exit(1);
    }

    printf("Command output: \n");
    while (fgets(path, sizeof(path), fp) != NULL) {
        printf("%s", path);
    }

    pclose(fp);
    return 0;
}