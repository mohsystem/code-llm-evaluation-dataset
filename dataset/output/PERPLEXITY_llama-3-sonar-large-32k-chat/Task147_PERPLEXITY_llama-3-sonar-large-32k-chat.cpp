#include <iostream>
#include <algorithm>

using namespace std;

int find_kth_largest(int nums[], int n, int k) {
    sort(nums, nums + n);
    return nums[n - k];
}

int main() {
    int n, k;
    cout << "Enter the number of elements: ";
    cin >> n;
    int nums[n];
    cout << "Enter the array of integers: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << "Enter the value of k: ";
    cin >> k;
    cout << "The kth largest element is: " << find_kth_largest(nums, n, k) << endl;
    return 0;
}