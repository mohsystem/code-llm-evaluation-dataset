// C
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Allocate memory buffer
    FILE *file = fopen("buffer.dat", "wb");
    char zero = 0;
    for (int i = 0; i < 1024; i++) {
        fwrite(&zero, sizeof(zero), 1, file);
    }
    fclose(file);

    // User input for index
    int index;
    printf("Enter index: ");
    scanf("%d", &index);

    // Read from buffer
    file = fopen("buffer.dat", "rb");
    fseek(file, index, SEEK_SET);
    char value;
    fread(&value, sizeof(value), 1, file);
    fclose(file);

    printf("Value at index: %d\n", value);

    return 0;
}