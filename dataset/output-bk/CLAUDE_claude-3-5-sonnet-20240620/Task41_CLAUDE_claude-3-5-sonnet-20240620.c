
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

void processString(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper((unsigned char)str[i]);
    }
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter a string: ");
    if (fgets(input, sizeof(input), stdin) != NULL) {
        size_t len = strlen(input);
        if (len > 0 && input[len-1] == \'\
\') {
            input[len-1] = \'\\0\';
        }
        processString(input);
        printf("Processed string: %s\
", input);
    } else {
        printf("Error reading input.\
");
    }
    return 0;
}
