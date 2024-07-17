#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("script.sh", "w");
    if (file == NULL) {
        printf("Error opening file!
");
        return 1;
    }
    fprintf(file, "#!/bin/bash
");
    fprintf(file, "echo Hello, World!");
    fclose(file);
    system("chmod +x script.sh");
    printf("script.sh created and made executable.
");
    return 0;
}