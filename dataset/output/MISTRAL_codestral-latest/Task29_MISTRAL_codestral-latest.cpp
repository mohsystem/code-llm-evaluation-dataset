#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& numbers, int target) {
    std::unordered_map<int, int> map;
    for (int i = 0; i < numbers.size(); i++) {
        int complement = target - numbers[i];
        if (map.find(complement) != map.end()) {
            return { map[complement], i };
        }
        map[numbers[i]] = i;
    }
    throw std::invalid_argument("No two sum solution");
}