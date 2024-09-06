#include <stdio.h>

void two_sum(int numbers[], int length, int target, int result[]) {
    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            if (numbers[i] + numbers[j] == target) {
                result[0] = i;
                result[1] = j;
                return;
            }
        }
    }
}

int main() {
    int numbers1[] = { 1, 2, 3 };
    int target1 = 4;
    int result1[2];
    two_sum(numbers1, 3, target1, result1);
    printf("{%d, %d}\n", result1[0], result1[1]);

    int numbers2[] = { 3, 2, 4 };
    int target2 = 6;
    int result2[2];
    two_sum(numbers2, 3, target2, result2);
    printf("{%d, %d}\n", result2[0], result2[1]);

    return 0;
}