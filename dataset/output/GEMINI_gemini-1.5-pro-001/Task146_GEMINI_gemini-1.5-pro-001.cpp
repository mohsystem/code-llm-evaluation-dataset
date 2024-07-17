#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int findMissingNumber(vector<int> arr) {
    int n = arr.size() + 1;
    int expectedSum = n * (n + 1) / 2;
    int actualSum = accumulate(arr.begin(), arr.end(), 0);
    return expectedSum - actualSum;
}

int main() {
    vector<int> arr = {1, 2, 4, 5, 6};
    int missingNumber = findMissingNumber(arr);
    cout << "The missing number is: " << missingNumber << endl;
    return 0;
}