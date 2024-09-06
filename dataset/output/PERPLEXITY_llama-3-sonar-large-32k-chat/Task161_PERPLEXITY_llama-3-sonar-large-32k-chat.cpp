#include <iostream>
#include <vector>

using namespace std;

int knapsack(int capacity, vector<int> weights, vector<int> values) {
    int n = values.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    int capacity;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;
    int n;
    cout << "Enter the number of items: ";
    cin >> n;
    vector<int> weights(n);
    vector<int> values(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter the weight of item " << (i + 1) << ": ";
        cin >> weights[i];
        cout << "Enter the value of item " << (i + 1) << ": ";
        cin >> values[i];
    }

    int maxValue = knapsack(capacity, weights, values);
    cout << "Maximum value that can be put into the knapsack: " << maxValue << endl;
    return 0;
}