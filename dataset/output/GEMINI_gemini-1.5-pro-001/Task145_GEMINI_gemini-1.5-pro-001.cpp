#include <iostream>
#include <vector>

using namespace std;

vector<int> maxSubarraySum(vector<int> arr) {
    int maxSoFar = INT_MIN;
    int currentMax = 0;
    int startIndex = 0;
    int endIndex = 0;
    int j = 0;

    for (int i = 0; i < arr.size(); i++) {
        currentMax += arr[i];

        if (currentMax > maxSoFar) {
            maxSoFar = currentMax;
            startIndex = j;
            endIndex = i;
        }

        if (currentMax < 0) {
            currentMax = 0;
            j = i + 1;
        }
    }

    // Extract the subarray with maximum sum
    vector<int> maxSubarray(&arr[startIndex], &arr[endIndex + 1]);
    return maxSubarray;
}

int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> maxSubArray = maxSubarraySum(arr);
    cout << "Maximum contiguous subarray: [";
    for (int i = 0; i < maxSubArray.size(); i++) {
        cout << maxSubArray[i];
        if (i < maxSubArray.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    return 0;
}