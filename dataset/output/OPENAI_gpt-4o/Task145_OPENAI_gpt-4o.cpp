#include <iostream>
#include <vector>
using namespace std;

int maxSubArraySum(vector<int>& arr) {
    int maxCurrent = arr[0];
    int maxGlobal = arr[0];

    for (size_t i = 1; i < arr.size(); ++i) {
        maxCurrent = max(arr[i], maxCurrent + arr[i]);
        if (maxCurrent > maxGlobal) {
            maxGlobal = maxCurrent;
        }
    }
    return maxGlobal;
}

int main() {
    vector<int> arr = {1, -3, 2, 1, -1};
    cout << "Max contiguous subarray sum is: " << maxSubArraySum(arr) << endl;
    return 0;
}