#include <stdio.h>
#include <limits.h>

void removeSmallest(int numbers[], int length) {
    if (length == 0) return;
    int minIndex = 0;
    for (int i = 1; i < length; i++) {
        if (numbers[i] < numbers[minIndex]) {
            minIndex = i;
        }
    }
    for (int i = 0; i < length; i++) {
        if (i != minIndex) {
            printf("%d ", numbers[i]);
        }
    }
    printf("
");
}

int main() {
    int numbers[] = {5, 3, 2, 1, 4};
    int length = sizeof(numbers) / sizeof(numbers[0]);
    removeSmallest(numbers, length);
    return 0;
}