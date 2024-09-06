#include <stdio.h>
#include <stdlib.h>
int main() {
    char filename[100];
    printf("Enter the filename: ");
    scanf("%s", filename);
    char command[150] = "cat ";
    strcat(command, filename);
    system(command);
    return 0;
}