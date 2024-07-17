
#include <stdio.h>
#include <stdlib.h>

int main() {
    const int bufferSize = 100;
    char* buffer = (char*)malloc(bufferSize * sizeof(char));
    
    if (buffer == NULL) {
        printf("Memory allocation failed\
");
        return 1;
    }
    
    // Fill buffer with some data
    for (int i = 0; i < bufferSize; i++) {
        buffer[i] = \'A\' + (i % 26);
    }
    
    while (1) {
        int index;
        printf("Enter an index to read (0-99), or -1 to exit: ");
        if (scanf("%d", &index) != 1) {
            printf("Invalid input. Please enter a number.\
");
            while (getchar() != \'\
\'); // Clear input buffer
            continue;
        }
        
        if (index == -1) {
            break;
        }
        
        if (index >= 0 && index < bufferSize) {
            printf("Data at index %d: %c\
", index, buffer[index]);
        } else {
            printf("Invalid index. Please enter a number between 0 and 99.\
");
        }
    }
    
    printf("Program terminated.\
");
    free(buffer);
    return 0;
}
