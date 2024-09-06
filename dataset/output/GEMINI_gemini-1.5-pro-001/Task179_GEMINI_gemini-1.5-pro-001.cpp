#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty()) {
            return {};
        }
        if (k == 1) {
            return nums;
        }
        
        int n = nums.size();
        vector<int> max_left(n);
        vector<int> max_right(n);
        max_left[0] = nums[0];
        max_right[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++) {
            max_left[i] = (i % k == 0) ? nums[i] : max(max_left[i - 1], nums[i]);
            int j = n - i - 1;
            max_right[j] = ((j + 1) % k == 0) ? nums[j] : max(max_right[j + 1], nums[j]);
        }

        vector<int> result(n - k + 1);
        for (int i = 0; i < n - k + 1; i++) {
            result[i] = max(max_right[i], max_left[i + k - 1]);
        }

        return result;
    }
};