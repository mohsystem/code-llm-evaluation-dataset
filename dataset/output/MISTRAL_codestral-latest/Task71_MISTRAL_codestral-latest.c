#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Invalid input. Please enter an integer.\n");
        return 1;
    }

    char* end;
    long num = strtol(argv[1], &end, 10);

    if (*end != '\0') {
        printf("Invalid input. Please enter an integer.\n");
    } else {
        printf("%ld\n", num);
    }

    return 0;
}