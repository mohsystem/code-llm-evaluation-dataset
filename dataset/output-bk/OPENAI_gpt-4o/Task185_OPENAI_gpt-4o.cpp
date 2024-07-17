#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
        return findMedianSortedArrays(nums2, nums1);
    }
    
    int m = nums1.size(), n = nums2.size();
    int half = (m + n + 1) / 2;
    int l = 0, r = m;
    
    while (l <= r) {
        int i = (l + r) / 2;
        int j = half - i;
        
        int Aleft = (i == 0) ? INT_MIN : nums1[i - 1];
        int Aright = (i == m) ? INT_MAX : nums1[i];
        int Bleft = (j == 0) ? INT_MIN : nums2[j - 1];
        int Bright = (j == n) ? INT_MAX : nums2[j];
        
        if (Aleft <= Bright && Bleft <= Aright) {
            if ((m + n) % 2) {
                return max(Aleft, Bleft);
            }
            return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
        }
        if (Aleft > Bright) r = i - 1;
        else l = i + 1;
    }
    return 0.0;
}

int main() {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}