#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char input[] = "HelloWorld";
    int shift = 3;
    char encrypted[sizeof(input)];
    
    for (int i = 0; i < strlen(input); i++) {
        char c = input[i];
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            encrypted[i] = (c - base + shift) % 26 + base;
        } else {
            encrypted[i] = c;
        }
    }
    encrypted[strlen(input)] = '\0';
    
    printf("C: %s
", encrypted);
    
    return 0;
}
main();