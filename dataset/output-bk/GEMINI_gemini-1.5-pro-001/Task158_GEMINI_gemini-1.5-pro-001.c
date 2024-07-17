#include <stdio.h>
#include <stdlib.h>

int main() {
    char command[1024];
    printf("Enter OS command: ");
    fgets(command, sizeof(command), stdin);
    system(command);
    return 0;
}