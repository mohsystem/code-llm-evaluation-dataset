#include <vector>
#include <algorithm>

std::vector<int> remove_smallest(const std::vector<int>& numbers) {
    if (numbers.empty()) {
        return {};
    }
    auto smallest_it = std::min_element(numbers.begin(), numbers.end());
    std::vector<int> result(numbers.begin(), smallest_it);
    result.insert(result.end(), smallest_it + 1, numbers.end());
    return result;
}