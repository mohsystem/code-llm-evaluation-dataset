
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(int capacity, vector<int>& weights, vector<int>& values, int n) {
    vector<vector<int>> K(n + 1, vector<int>(capacity + 1, 0));
    
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (weights[i-1] <= w)
                K[i][w] = max(values[i-1] + K[i-1][w-weights[i-1]], K[i-1][w]);
            else
                K[i][w] = K[i-1][w];
        }
    }
    
    return K[n][capacity];
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
    
    cout << "Maximum value in Knapsack = " << knapsack(capacity, weights, values, n) << endl;
    
    return 0;
}
