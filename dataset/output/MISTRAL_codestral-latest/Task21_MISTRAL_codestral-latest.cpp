#include <vector>
#include <algorithm>

std::vector<int> remove_smallest(std::vector<int> numbers) {
    if (!numbers.empty()) {
        numbers.erase(std::min_element(numbers.begin(), numbers.end()));
    }
    return numbers;
}