#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char filename[256];
    printf("Enter a filename: ");
    scanf("%255s", filename);
    char command[512];
    sprintf(command, "cat %s", filename);
    system(command);
    return 0;
}