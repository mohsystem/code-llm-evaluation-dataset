
#include <stdio.h>
#include <string.h>

const char* odd_or_even(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum % 2 == 0 ? "even" : "odd";
}

int main() {
    int arr1[] = {0};
    int arr2[] = {0, 1, 4};
    int arr3[] = {0, -1, -5};

    printf("%s\\n", odd_or_even(arr1, sizeof(arr1) / sizeof(arr1[0])));  // Output: "even"
    printf("%s\\n", odd_or_even(arr2, sizeof(arr2) / sizeof(arr2[0])));  // Output: "odd"
    printf("%s\\n", odd_or_even(arr3, sizeof(arr3) / sizeof(arr3[0])));  // Output: "even"

    return 0;
}
