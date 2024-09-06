
#include <vector>
#include <unordered_map>

class Solution {
public:
    static std::vector<int> twoSum(const std::vector<int>& numbers, int target) {
        std::unordered_map<int, int> numMap;
        for (int i = 0; i < numbers.size(); i++) {
            int complement = target - numbers[i];
            if (numMap.find(complement) != numMap.end()) {
                return {numMap[complement], i};
            }
            numMap[numbers[i]] = i;
        }
        return {};
    }
};
