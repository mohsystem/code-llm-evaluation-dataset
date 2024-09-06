#include <iostream>
#include <deque>
#include <vector>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    if (nums.empty()) return {};
    
    deque<int> deq;
    vector<int> result;

    for (int i = 0; i < nums.size(); ++i) {
        if (!deq.empty() && deq.front() == i - k) {
            deq.pop_front();
        }
        while (!deq.empty() && nums[deq.back()] < nums[i]) {
            deq.pop_back();
        }
        deq.push_back(i);
        
        if (i >= k - 1) {
            result.push_back(nums[deq.front()]);
        }
    }
    return result;
}

int main() {
    vector<int> nums1 = {1, 3, -1, -3, 5, 3, 6, 7};
    int k1 = 3;
    vector<int> result1 = maxSlidingWindow(nums1, k1);
   
    for (int n : result1) {
        cout << n << " ";  // [3,3,5,5,6,7]
    }
    cout << endl;

    vector<int> nums2 = {1};
    int k2 = 1;
    vector<int> result2 = maxSlidingWindow(nums2, k2);

    for (int n : result2) {
        cout << n << " ";  // [1]
    }
    cout << endl;

    return 0;
}