#include <iostream>
#include <vector>

using namespace std;

int findEvenIndex(const vector<int>& arr) {
    if (arr.empty()) {
        return 0;
    }
    for (size_t i = 0; i < arr.size(); i++) {
        int leftSum = 0;
        int rightSum = 0;
        for (size_t j = 0; j < i; j++) {
            leftSum += arr[j];
        }
        for (size_t j = i + 1; j < arr.size(); j++) {
            rightSum += arr[j];
        }
        if (leftSum == rightSum) {
            return i;
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 3, 2, 1};
    int result = findEvenIndex(arr);
    cout << result << endl; // Output: 3
    return 0;
}