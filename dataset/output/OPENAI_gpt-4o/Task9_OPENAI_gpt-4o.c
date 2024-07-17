#include <stdio.h>

const char* oddOrEven(int arr[], int size) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (sum % 2 == 0) ? "even" : "odd";
}

int main() {
    int arr[] = {0, -1, -5}; // Example input array
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("%s
", oddOrEven(arr, size));
    return 0;
}