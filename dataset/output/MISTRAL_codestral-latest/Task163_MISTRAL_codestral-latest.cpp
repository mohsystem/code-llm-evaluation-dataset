#include <algorithm>
#include <vector>

int longestRun(std::vector<int> arr) {
    if (arr.empty()) {
        return 0;
    }
    int longest = 1;
    int current = 1;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] == arr[i-1] + 1 || arr[i] == arr[i-1] - 1) {
            current++;
        } else {
            longest = std::max(longest, current);
            current = 1;
        }
    }
    return std::max(longest, current);
}