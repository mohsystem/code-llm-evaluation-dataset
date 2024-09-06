code here:
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

int main() {
    char buffer[BUFFER_SIZE][256];
    int index = 0;

    while (true) {
        printf("Enter a value (or 'quit' to exit): ");
        char userInput[256];
        fgets(userInput, 256, stdin);
        userInput[strcspn(userInput, "\n")] = 0; // remove newline character
        if (strcmp(userInput, "quit") == 0) {
            break;
        }
        if (index < BUFFER_SIZE) {
            strcpy(buffer[index], userInput);
            index++;
        } else {
            printf("Buffer is full. Oldest value will be replaced.\n");
            for (int i = 0; i < BUFFER_SIZE - 1; i++) {
                strcpy(buffer[i], buffer[i + 1]);
            }
            strcpy(buffer[BUFFER_SIZE - 1], userInput);
        }
        printf("Buffer: ");
        for (int i = 0; i < BUFFER_SIZE; i++) {
            printf("%s ", buffer[i]);
        }
        printf("\n");
    }
    return 0;
}