#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./program <filename>\n");
        return 1;
    }
    
    char *filename = argv[1];
    
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error");
        return 1;
    }
    
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    
    fclose(file);
    return 0;
}