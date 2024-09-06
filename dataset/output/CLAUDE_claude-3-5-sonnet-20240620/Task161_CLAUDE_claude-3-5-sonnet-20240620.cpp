
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(int capacity, vector<int>& weights, vector<int>& values, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (weights[i-1] <= w) {
                dp[i][w] = max(values[i-1] + dp[i-1][w-weights[i-1]], dp[i-1][w]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    
    return dp[n][capacity];
}

int main() {
    int capacity, n;
    
    cout << "Enter knapsack capacity: ";
    cin >> capacity;
    
    cout << "Enter number of items: ";
    cin >> n;
    
    vector<int> weights(n);
    vector<int> values(n);
    
    cout << "Enter weights of items: ";
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }
    
    cout << "Enter values of items: ";
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }
    
    cout << "Maximum value: " << knapsack(capacity, weights, values, n) << endl;
    
    return 0;
}
