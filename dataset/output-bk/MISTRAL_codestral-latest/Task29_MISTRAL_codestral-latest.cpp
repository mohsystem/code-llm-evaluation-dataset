#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& numbers, int target) {
    std::unordered_map<int, int> numMap;
    for (int i = 0; i < numbers.size(); i++) {
        if (numMap.find(target - numbers[i]) != numMap.end()) {
            return {numMap[target - numbers[i]], i};
        }
        numMap[numbers[i]] = i;
    }
    return {};
}