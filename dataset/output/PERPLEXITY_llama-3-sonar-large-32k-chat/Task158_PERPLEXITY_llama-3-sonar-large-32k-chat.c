#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char data[100];
    printf("Enter data: ");
    fgets(data, sizeof(data), stdin);
    data[strcspn(data, "\n")] = 0; // remove newline character
    char command[150];
    sprintf(command, "echo %s > output.txt", data);
    system(command);
    return 0;
}