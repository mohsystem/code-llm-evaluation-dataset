#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> sortedArr;
        vector<int> counts(n);

        for (int i = n - 1; i >= 0; i--) {
            int index = lower_bound(sortedArr.begin(), sortedArr.end(), nums[i]) - sortedArr.begin();
            counts[i] = index;
            sortedArr.insert(sortedArr.begin() + index, nums[i]);
        }

        return counts;
    }
};