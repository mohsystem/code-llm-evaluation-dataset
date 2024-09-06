#include <stdio.h>
#include <limits.h>

int find_min_index(int tills[], int n) {
    int min_index = 0;
    for (int i = 1; i < n; i++) {
        if (tills[i] < tills[min_index]) {
            min_index = i;
        }
    }
    return min_index;
}

int queueTime(int customers[], int length, int n) {
    int tills[n];
    for (int i = 0; i < n; i++) {
        tills[i] = 0;
    }
    for (int i = 0; i < length; i++) {
        int index = find_min_index(tills, n);
        tills[index] += customers[i];
    }
    int max_time = 0;
    for (int i = 0; i < n; i++) {
        if (tills[i] > max_time) {
            max_time = tills[i];
        }
    }
    return max_time;
}

int main() {
    int customers1[] = {5, 3, 4};
    int customers2[] = {10, 2, 3, 3};
    int customers3[] = {2, 3, 10};

    printf("%d\n", queueTime(customers1, 3, 1)); // should return 12
    printf("%d\n", queueTime(customers2, 4, 2)); // should return 10
    printf("%d\n", queueTime(customers3, 3, 2)); // should return 12

    return 0;
}