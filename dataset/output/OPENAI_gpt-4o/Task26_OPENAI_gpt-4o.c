#include <stdio.h>

int findOddOccurrence(int arr[], int size) {
    int result = 0;
    for (int i = 0; i < size; i++) {
        result ^= arr[i];
    }
    return result;
}

int main() {
    printf("%d\n", findOddOccurrence((int[]){7}, 1));
    printf("%d\n", findOddOccurrence((int[]){0}, 1));
    printf("%d\n", findOddOccurrence((int[]){1, 1, 2}, 3));
    printf("%d\n", findOddOccurrence((int[]){0, 1, 0, 1, 0}, 5));
    printf("%d\n", findOddOccurrence((int[]){1, 2, 2, 3, 3, 3, 4, 3, 3, 3, 2, 2, 1}, 13));
    return 0;
}