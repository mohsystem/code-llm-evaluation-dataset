#include <vector>
#include <algorithm>

std::vector<int> removeSmallest(std::vector<int> numbers) {
    if (numbers.empty()) {
        return {};
    }
    int minIndex = std::distance(numbers.begin(), std::min_element(numbers.begin(), numbers.end()));
    numbers.erase(numbers.begin() + minIndex);
    return numbers;
}