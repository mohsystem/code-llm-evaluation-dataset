
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRINGS 100
#define MAX_LENGTH 1000

int main() {
    char strings[MAX_STRINGS][MAX_LENGTH];
    char result[MAX_STRINGS * MAX_LENGTH] = "";
    int count = 0;

    while (1) {
        printf("Enter a string (or press Enter to finish): ");
        fgets(strings[count], MAX_LENGTH, stdin);
        
        // Remove newline character
        strings[count][strcspn(strings[count], "\\n")] = 0;

        if (strings[count][0] == '\\0') {
            break;
        }

        count++;
        if (count >= MAX_STRINGS) {
            printf("Maximum number of strings reached.\\n");
            break;
        }
    }

    for (int i = 0; i < count; i++) {
        if (i > 0) {
            strcat(result, " ");
        }
        strcat(result, strings[i]);
    }

    printf("Concatenated string: %s\\n", result);

    return 0;
}
