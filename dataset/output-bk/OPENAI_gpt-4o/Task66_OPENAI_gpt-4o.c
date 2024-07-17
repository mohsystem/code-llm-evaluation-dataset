#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isValidCommand(const char *command) {
    while (*command) {
        if (!((*command >= 'A' && *command <= 'Z') || 
              (*command >= 'a' && *command <= 'z') ||
              (*command >= '0' && *command <= '9') ||
              strchr(" -_/", *command))) {
            return false;
        }
        command++;
    }
    return true;
}

int main() {
    char command[256];
    
    printf("Enter shell command: ");
    fgets(command, sizeof(command), stdin);
    command[strcspn(command, "
")] = 0; // remove the trailing newline

    if (isValidCommand(command)) {
        FILE *fp;
        char path[1035];

        fp = popen(command, "r");
        if (fp == NULL) {
            printf("Failed to run command
" );
            exit(1);
        }

        while (fgets(path, sizeof(path), fp) != NULL) {
            printf("%s", path);
        }

        pclose(fp);
    } else {
        printf("Invalid command.
");
    }

    return 0;
}