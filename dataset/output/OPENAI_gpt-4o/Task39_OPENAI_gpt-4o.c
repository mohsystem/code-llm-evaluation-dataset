#include <stdio.h>
#include <stdlib.h>

int main() {
    char filename[100];
    
    printf("Enter the filename: ");
    scanf("%s", filename);

    char command[150];
    sprintf(command, "cat %s", filename);

    system(command);
    
    return 0;
}