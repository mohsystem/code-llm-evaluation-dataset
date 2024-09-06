// C++ code
#include<iostream>
using namespace std;

int knapsack(int capacity, int weights[], int values[], int n) {
    if (n == 0 || capacity == 0)
        return 0;
    if (weights[n-1] > capacity)
        return knapsack(capacity, weights, values, n-1);
    else
        return max(values[n-1] + knapsack(capacity-weights[n-1], weights, values, n-1), knapsack(capacity, weights, values, n-1));
}

int main() {
    int capacity = 50;
    int values[] = {60, 100, 120};
    int weights[] = {10, 20, 30};
    int n = sizeof(values)/sizeof(values[0]);
    cout << knapsack(capacity, weights, values, n);
    return 0;
}