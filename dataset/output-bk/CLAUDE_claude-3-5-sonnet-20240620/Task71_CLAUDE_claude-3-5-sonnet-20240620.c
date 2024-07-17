
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Please provide a string argument.\
");
        return 1;
    }
    
    char *input = argv[1];
    char *endptr;
    long result = strtol(input, &endptr, 10);
    
    if (*endptr != \'\\0\') {
        printf("Invalid input. Cannot convert to integer.\
");
    } else {
        printf("Converted integer: %ld\
", result);
    }
    
    return 0;
}
