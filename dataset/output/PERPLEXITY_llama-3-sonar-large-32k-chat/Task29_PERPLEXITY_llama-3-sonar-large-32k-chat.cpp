#include <vector>
std::vector<int> two_sum(std::vector<int> numbers, int target) {
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            if (numbers[i] + numbers[j] == target) {
                return std::vector<int> {i, j};
            }
        }
    }
    return std::vector<int> {};
}