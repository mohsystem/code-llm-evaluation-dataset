code here:
#include <stdio.h>
#include <stdlib.h>

int main() {
    int bufferSize;
    printf("Enter the buffer size: ");
    scanf("%d", &bufferSize);
    int* buffer = (int*) malloc(bufferSize * sizeof(int));
    for (int i = 0; i < bufferSize; i++) {
        buffer[i] = i;
    }
    while (true) {
        int index;
        printf("Enter the index to read from the buffer (or -1 to exit): ");
        scanf("%d", &index);
        if (index == -1) {
            break;
        }
        if (index < 0 || index >= bufferSize) {
            printf("Invalid index\n");
        } else {
            printf("Buffer[%d] = %d\n", index, buffer[index]);
        }
    }
    free(buffer);
    return 0;
}