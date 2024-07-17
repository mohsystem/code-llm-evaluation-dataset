
#include <vector>
#include <algorithm>

class Solution {
public:
    static std::vector<int> removeSmallest(std::vector<int> numbers) {
        if (numbers.empty()) {
            return {};
        }
        
        std::vector<int> result = numbers;
        auto minIt = std::min_element(result.begin(), result.end());
        result.erase(minIt);
        return result;
    }
};
