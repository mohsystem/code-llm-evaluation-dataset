#include <iostream>
#include <numeric>
using namespace std;

int findEqualIndex(int arr[], int length) {
    int totalSum = accumulate(arr, arr + length, 0);
    int leftSum = 0;

    for (int i = 0; i < length; ++i) {
        if (leftSum == totalSum - leftSum - arr[i])
            return i;
        leftSum += arr[i];
    }
    return -1;
}

int main() {
    int arr[] = {20, 10, -80, 10, 10, 15, 35};
    int length = sizeof(arr) / sizeof(arr[0]);
    cout << findEqualIndex(arr, length) << endl;
    return 0;
}