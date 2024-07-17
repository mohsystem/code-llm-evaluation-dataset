#include <vector>
#include <set>
#include <algorithm>

std::vector<int> countSmaller(std::vector<int>& nums) {
    std::vector<int> result;
    std::multiset<int> sortedSet;
    for (int i = nums.size() - 1; i >= 0; i--) {
        auto it = sortedSet.upper_bound(nums[i]);
        int index = std::distance(sortedSet.begin(), it);
        result.push_back(index);
        sortedSet.insert(nums[i]);
    }
    std::reverse(result.begin(), result.end());
    return result;
}