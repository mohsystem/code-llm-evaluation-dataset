
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int capacity, int* weights, int* values, int n) {
    int i, w;
    int** K = (int**)malloc((n + 1) * sizeof(int*));
    for (i = 0; i <= n; i++) {
        K[i] = (int*)malloc((capacity + 1) * sizeof(int));
    }
    
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (weights[i-1] <= w)
                K[i][w] = max(values[i-1] + K[i-1][w-weights[i-1]], K[i-1][w]);
            else
                K[i][w] = K[i-1][w];
        }
    }
    
    int result = K[n][capacity];
    
    for (i = 0; i <= n; i++) {
        free(K[i]);
    }
    free(K);
    
    return result;
}

int main() {
    int capacity, n, i;
    
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);
    
    printf("Enter number of items: ");
    scanf("%d", &n);
    
    int* weights = (int*)malloc(n * sizeof(int));
    int* values = (int*)malloc(n * sizeof(int));
    
    printf("Enter weights of items: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }
    
    printf("Enter values of items: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }
    
    printf("Maximum value in Knapsack = %d\
", knapsack(capacity, weights, values, n));
    
    free(weights);
    free(values);
    
    return 0;
}
