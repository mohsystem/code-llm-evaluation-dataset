#include <stdio.h>

void createPhoneNumber(int arr[10], char* buffer) {
    snprintf(buffer, 15, "(%d%d%d) %d%d%d-%d%d%d%d", 
             arr[0], arr[1], arr[2], 
             arr[3], arr[4], arr[5], 
             arr[6], arr[7], arr[8], 
             arr[9]);
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    char buffer[15];
    createPhoneNumber(arr, buffer);
    printf("%s\n", buffer);
    return 0;
}