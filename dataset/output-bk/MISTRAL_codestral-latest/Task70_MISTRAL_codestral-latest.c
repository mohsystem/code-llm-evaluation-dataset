#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (file) {
            char line[256];
            while (fgets(line, sizeof(line), file)) {
                printf("%s", line);
            }
            fclose(file);
        } else {
            printf("Unable to open the file.
");
        }
    } else {
        printf("Please provide a file path as an argument.
");
    }
    return 0;
}