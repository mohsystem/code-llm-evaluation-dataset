
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int capacity, int* weights, int* values, int n) {
    int** dp = (int**)malloc((n + 1) * sizeof(int*));
    for (int i = 0; i <= n; i++) {
        dp[i] = (int*)calloc(capacity + 1, sizeof(int));
    }
    
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (weights[i-1] <= w) {
                dp[i][w] = max(values[i-1] + dp[i-1][w-weights[i-1]], dp[i-1][w]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    
    int result = dp[n][capacity];
    
    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);
    
    return result;
}

int main() {
    int capacity, n;
    
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);
    
    printf("Enter number of items: ");
    scanf("%d", &n);
    
    int* weights = (int*)malloc(n * sizeof(int));
    int* values = (int*)malloc(n * sizeof(int));
    
    printf("Enter weights of items: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }
    
    printf("Enter values of items: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }
    
    printf("Maximum value: %d\\n", knapsack(capacity, weights, values, n));
    
    free(weights);
    free(values);
    
    return 0;
}
