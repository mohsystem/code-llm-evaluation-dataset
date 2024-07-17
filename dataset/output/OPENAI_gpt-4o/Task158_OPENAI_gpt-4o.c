#include <stdio.h>
#include <stdlib.h>

int main() {
    char command[256];
    printf("Enter a command to run: ");
    fgets(command, sizeof(command), stdin);
    system(command);
    return 0;
}