#include <stdio.h>

char* sumType(int arr[], int size) {
    if (size == 0) {
        arr[0] = 0;
        size = 1;
    }
    int sum = 0;
    for (int i = 0; i < size; i++) sum += arr[i];
    return sum % 2 == 0 ? "even" : "odd";
}

int main() {
    int arr[] = {0, 1, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("%s
", sumType(arr, size));
    return 0;
}