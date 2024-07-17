#include <iostream>
#include <unordered_map>

using namespace std;

int findOdd(int arr[], int n) {
    unordered_map<int, int> count;
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    for (auto it : count) {
        if (it.second % 2 != 0) {
            return it.first;
        }
    }

    return -1;
}

int main() {
    int arr1[] = {7};
    int arr2[] = {0};
    int arr3[] = {1, 1, 2};
    int arr4[] = {0, 1, 0, 1, 0};
    int arr5[] = {1, 2, 2, 3, 3, 3, 4, 3, 3, 3, 2, 2, 1};

    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    int n5 = sizeof(arr5) / sizeof(arr5[0]);

    cout << findOdd(arr1, n1) << endl;
    cout << findOdd(arr2, n2) << endl;
    cout << findOdd(arr3, n3) << endl;
    cout << findOdd(arr4, n4) << endl;
    cout << findOdd(arr5, n5) << endl;

    return 0;
}