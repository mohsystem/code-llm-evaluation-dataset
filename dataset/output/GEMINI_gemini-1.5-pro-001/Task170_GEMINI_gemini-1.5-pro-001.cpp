#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<int> preSum(n);
        preSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            preSum[i] = preSum[i - 1] + nums[i];
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int lo = i;
            int hi = n - 1;
            int idx = -1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                int cur = preSum[mid];
                if (i > 0) {
                    cur -= preSum[i - 1];
                }
                if (cur < lower) {
                    lo = mid + 1;
                } else {
                    idx = mid;
                    hi = mid - 1;
                }
            }
            if (idx != -1) {
                int cur = preSum[idx];
                if (i > 0) {
                    cur -= preSum[i - 1];
                }
                if (lower <= cur && cur <= upper) {
                    ans++;
                }
            }
        }
        return ans;
    }
};