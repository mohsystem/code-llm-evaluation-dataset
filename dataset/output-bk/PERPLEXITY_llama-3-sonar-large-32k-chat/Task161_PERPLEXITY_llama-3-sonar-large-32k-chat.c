#include <stdio.h>

int knapsack(int W, int wt[], int val[], int n) {
    int K[n + 1][W + 1];
    
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i-1] <= w)
                K[i][w] = (val[i-1] + K[i-1][w-wt[i-1]] > K[i-1][w]) ? val[i-1] + K[i-1][w-wt[i-1]] : K[i-1][w];
            else
                K[i][w] = K[i-1][w];
        }
    }
 
    return K[n][W];
}

int main() {
    int W, n;
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);
    printf("Enter the number of items: ");
    scanf("%d", &n);
    int val[n], wt[n];
    printf("Enter the values of the items: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val[i]);
    }
    printf("Enter the weights of the items: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &wt[i]);
    }
    
    printf("Maximum value that can be put into the knapsack: %d
", knapsack(W, wt, val, n));
    return 0;
}