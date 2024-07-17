#include <iostream>
#include <vector>

std::vector<int> removeSmallest(std::vector<int> numbers) {
    if (numbers.empty()) return numbers;
    auto minIt = std::min_element(numbers.begin(), numbers.end());
    numbers.erase(minIt);
    return numbers;
}

int main() {
    std::vector<int> numbers = {5, 3, 2, 1, 4};
    std::vector<int> result = removeSmallest(numbers);
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}