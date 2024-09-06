#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *source = fopen("source_file.txt", "rb");
    FILE *dest = fopen("destination_file.txt", "wb");

    if (source == NULL || dest == NULL) {
        perror("An error occurred");
        return 1;
    }

    int c;
    while ((c = fgetc(source)) != EOF) {
        fputc(c, dest);
    }

    fclose(source);
    fclose(dest);

    return 0;
}