#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        multiset<long> prefixSums;
        prefixSums.insert(0);
        long currentSum = 0;
        int count = 0;

        for (int num : nums) {
            currentSum += num;
            count += distance(prefixSums.lower_bound(currentSum - upper), 
                              prefixSums.upper_bound(currentSum - lower));
            prefixSums.insert(currentSum);
        }
        
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-2, 5, -1};
    int lower = -2;
    int upper = 2;
    cout << sol.countRangeSum(nums, lower, upper) << endl;  // Output: 3
    return 0;
}