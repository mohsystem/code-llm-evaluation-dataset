
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

int main() {
    char result[MAX_LENGTH] = "";
    char input[MAX_LENGTH];
    
    printf("Enter strings to concatenate (type \'done\' to finish):\
");
    
    while (1) {
        fgets(input, MAX_LENGTH, stdin);
        input[strcspn(input, "\
")] = 0;  // Remove newline
        
        if (strcmp(input, "done") == 0) {
            break;
        }
        
        strcat(result, input);
    }
    
    printf("Concatenated string: %s\
", result);
    
    return 0;
}
