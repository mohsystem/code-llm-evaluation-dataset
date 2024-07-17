
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 1000

int main() {
    char userInput[MAX_INPUT];
    char command[MAX_INPUT + 5];  // 5 extra chars for "echo "
    
    printf("Enter data: ");
    fgets(userInput, MAX_INPUT, stdin);
    userInput[strcspn(userInput, "\
")] = 0;  // Remove newline
    
    snprintf(command, sizeof(command), "echo %s", userInput);
    system(command);
    
    return 0;
}
