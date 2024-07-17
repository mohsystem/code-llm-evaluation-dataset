#include <stdio.h>
#include <stdlib.h>

int main() {
    char filename[100];
    printf("Enter the filename: ");
    scanf("%s", filename);

    char command[150] = "cat ";
    strcat(command, filename);

    int result = system(command);
    if (result != 0) {
        fprintf(stderr, "Error displaying file.
");
        return 1;
    }

    return 0;
}