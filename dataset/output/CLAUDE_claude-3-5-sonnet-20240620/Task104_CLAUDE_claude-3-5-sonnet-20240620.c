
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

void handleUserInput(char* buffer, int bufferSize) {
    printf("Enter a string (max %d characters): ", bufferSize - 1);
    
    if (fgets(buffer, bufferSize, stdin) != NULL) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\\n') {
            buffer[len - 1] = '\\0';
        } else if (len == bufferSize - 1) {
            int c;
            while ((c = getchar()) != '\\n' && c != EOF);
            printf("Input too long. Truncated to %d characters.\\n", bufferSize - 1);
        }
    }

    printf("You entered: %s\\n", buffer);
}

int main() {
    char buffer[BUFFER_SIZE];
    handleUserInput(buffer, BUFFER_SIZE);
    return 0;
}
