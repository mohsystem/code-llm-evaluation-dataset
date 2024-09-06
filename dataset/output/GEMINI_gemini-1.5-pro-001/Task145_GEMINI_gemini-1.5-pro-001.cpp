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

    vector<int> resultArray(arr.begin() + startIndex, arr.begin() + endIndex + 1);
    return resultArray;
}

int main() {
    vector<int> inputArray = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> result = maxSubarraySum(inputArray);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}