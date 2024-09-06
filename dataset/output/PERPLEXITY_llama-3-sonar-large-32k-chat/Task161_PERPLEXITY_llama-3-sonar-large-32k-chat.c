#include <stdio.h>

int knapsack(int capacity, int* weights, int* values, int n) {
    int dp[n + 1][capacity + 1];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = (values[i - 1] + dp[i - 1][w - weights[i - 1]] > dp[i - 1][w]) ? values[i - 1] + dp[i - 1][w - weights[i - 1]] : dp[i - 1][w];
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    int capacity;
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    int* weights = (int*)malloc(n * sizeof(int));
    int* values = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Enter the weight of item %d: ", i + 1);
        scanf("%d", &weights[i]);
        printf("Enter the value of item %d: ", i + 1);
        scanf("%d", &values[i]);
    }

    int maxValue = knapsack(capacity, weights, values, n);
    printf("Maximum value that can be put into the knapsack: %d\n", maxValue);
    free(weights);
    free(values);
    return 0;
}