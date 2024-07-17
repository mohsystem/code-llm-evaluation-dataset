#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char data[256];
    printf("Enter data: ");
    fgets(data, 256, stdin);
    data[strcspn(data, "
")] = 0; // remove newline character
    char command[256];
    sprintf(command, "echo %s > output.txt", data);
    system(command);
    return 0;
}