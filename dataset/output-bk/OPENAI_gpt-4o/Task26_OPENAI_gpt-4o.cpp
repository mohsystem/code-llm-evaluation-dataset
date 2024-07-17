#include <iostream>
using namespace std;

int findOdd(int arr[], int n) {
    int res = 0;
    for (int i = 0; i < n; i++) {
        res ^= arr[i];
    }
    return res;
}

int main() {
    int arr[] = {1,2,2,3,3,3,4,3,3,3,2,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int result = findOdd(arr, n);
    cout << result << endl;
    return 0;
}