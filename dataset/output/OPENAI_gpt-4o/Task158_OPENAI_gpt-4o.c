#include <stdio.h>
#include <stdlib.h>

int main() {
    char command[256];
    printf("Enter the command to execute: ");
    fgets(command, 256, stdin);
    system(command);
    return 0;
}