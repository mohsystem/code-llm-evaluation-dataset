
#include <vector>
#include <algorithm>

std::vector<int> removeSmallest(std::vector<int> numbers) {
    if (numbers.empty()) return {};
    auto min_it = std::min_element(numbers.begin(), numbers.end());
    numbers.erase(min_it);
    return numbers;
}
