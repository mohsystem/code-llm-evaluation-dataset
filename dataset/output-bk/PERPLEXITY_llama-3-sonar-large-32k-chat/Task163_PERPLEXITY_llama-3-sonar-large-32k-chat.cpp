#include <iostream>
#include <algorithm>
#include <vector>

int longestRun(std::vector<int> arr) {
    if (arr.empty()) {
        return 0;
    }
    std::sort(arr.begin(), arr.end());
    int longest_run = 1;
    int current_run = 1;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] - arr[i-1] == 1) {
            current_run += 1;
        } else {
            longest_run = std::max(longest_run, current_run);
            current_run = 1;
        }
    }
    return std::max(longest_run, current_run);
}

int main() {
    std::vector<int> arr = {1, 2, 3, 5, 6, 7, 8, 9};
    std::cout << longestRun(arr) << std::endl;
    return 0;
}