#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    char buffer[BUFFER_SIZE];

    printf("Enter your input (max %d characters): ", BUFFER_SIZE);
    fgets(buffer, BUFFER_SIZE, stdin);

    // Remove trailing newline from fgets()
    buffer[strcspn(buffer, "\n")] = 0;

    printf("\nYou entered:\n%s\n", buffer);

    return 0;
}