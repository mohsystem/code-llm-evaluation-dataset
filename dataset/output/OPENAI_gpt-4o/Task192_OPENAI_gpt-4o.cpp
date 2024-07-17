#include <iostream>
#include <vector>

using namespace std;

bool xorGame(vector<int>& nums) {
    int xor_sum = 0;
    for (int num : nums) {
        xor_sum ^= num;
    }
    return xor_sum == 0 || nums.size() % 2 == 0;
}

int main() {
    vector<int> nums1 = {1, 1, 2};
    cout << xorGame(nums1) << endl; // Output: false

    vector<int> nums2 = {0, 1};
    cout << xorGame(nums2) << endl; // Output: true

    vector<int> nums3 = {1, 2, 3};
    cout << xorGame(nums3) << endl; // Output: true

    return 0;
}