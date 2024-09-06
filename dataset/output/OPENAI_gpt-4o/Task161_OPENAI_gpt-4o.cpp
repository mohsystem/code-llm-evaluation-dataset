#include <iostream>
#include <vector>
using namespace std;

int knapsack(int capacity, vector<int> weights, vector<int> values, int n) {
    vector<vector<int>> K(n + 1, vector<int>(capacity + 1));
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (weights[i - 1] <= w)
                K[i][w] = max(values[i - 1] + K[i - 1][w - weights[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][capacity];
}

int main() {
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int capacity = 50;
    int n = values.size();
    cout << knapsack(capacity, weights, values, n) << endl;
    return 0;
}