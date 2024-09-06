#include <stddef.h>

int find_even_index(int arr[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        int leftSum = 0;
        int rightSum = 0;
        for (size_t j = 0; j < i; j++) {
            leftSum += arr[j];
        }
        for (size_t j = i + 1; j < size; j++) {
            rightSum += arr[j];
        }
        if (leftSum == rightSum) {
            return i;
        }
    }
    return -1;
}