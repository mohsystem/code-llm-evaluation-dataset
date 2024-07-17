#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> removeSmallest(const std::vector<int>& numbers) {
    if (numbers.empty()) {
        return {}; // Return an empty vector if the input is empty
    }

    // Find the index of the smallest element
    int minIndex = std::distance(numbers.begin(), std::min_element(numbers.begin(), numbers.end()));

    // Create a new vector without the smallest element
    std::vector<int> result = numbers; // Copy the original vector
    result.erase(result.begin() + minIndex);

    return result;
}

int main() {
    std::vector<int> input = {2, 2, 1, 2, 1};
    std::vector<int> output = removeSmallest(input);

    // Print the output vector
    std::cout << "[";
    for (size_t i = 0; i < output.size(); ++i) {
        std::cout << output[i];
        if (i != output.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}