
#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[100];
    char *endptr;
    
    printf("Enter a number: ");
    fgets(input, sizeof(input), stdin);
    
    long number = strtol(input, &endptr, 10);
    
    if (*endptr != \'\
\' && *endptr != \'\\0\') {
        printf("Invalid input. Not a valid integer.\
");
    } else {
        printf("Converted integer: %ld\
", number);
    }
    
    return 0;
}
