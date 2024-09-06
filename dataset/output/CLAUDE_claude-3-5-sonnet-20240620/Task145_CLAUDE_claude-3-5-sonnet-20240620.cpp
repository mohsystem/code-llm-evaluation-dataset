
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int maxSubarraySum(vector<int>& arr) {
    int maxSum = INT_MIN;
    int currentSum = 0;
    
    for (int num : arr) {
        currentSum = max(num, currentSum + num);
        maxSum = max(maxSum, currentSum);
    }
    
    return maxSum;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the array elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int result = maxSubarraySum(arr);
    cout << "Maximum subarray sum: " << result << endl;
    
    return 0;
}
