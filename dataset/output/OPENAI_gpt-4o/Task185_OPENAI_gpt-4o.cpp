#include <iostream>
#include <vector>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> merged;
    int i = 0, j = 0;
    
    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] < nums2[j]) {
            merged.push_back(nums1[i++]);
        } else {
            merged.push_back(nums2[j++]);
        }
    }
    
    while (i < nums1.size()) {
        merged.push_back(nums1[i++]);
    }
    
    while (j < nums2.size()) {
        merged.push_back(nums2[j++]);
    }
    
    int len = merged.size();
    if (len % 2 == 0) {
        return (merged[len / 2 - 1] + merged[len / 2]) / 2.0;
    } else {
        return merged[len / 2];
    }
}

int main() {
    vector<int> nums1a = {1, 3};
    vector<int> nums2a = {2};
    cout << findMedianSortedArrays(nums1a, nums2a) << endl;
    
    vector<int> nums1b = {1, 2};
    vector<int> nums2b = {3, 4};
    cout << findMedianSortedArrays(nums1b, nums2b) << endl;
    
    return 0;
}